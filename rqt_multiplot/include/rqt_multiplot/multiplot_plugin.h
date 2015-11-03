/******************************************************************************
 * Copyright (C) 2015 by Ralf Kaestner                                        *
 * ralf.kaestner@gmail.com                                                    *
 *                                                                            *
 * This program is free software; you can redistribute it and/or modify       *
 * it under the terms of the Lesser GNU General Public License as published by*
 * the Free Software Foundation; either version 3 of the License, or          *
 * (at your option) any later version.                                        *
 *                                                                            *
 * This program is distributed in the hope that it will be useful,            *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the               *
 * Lesser GNU General Public License for more details.                        *
 *                                                                            *
 * You should have received a copy of the Lesser GNU General Public License   *
 * along with this program. If not, see <http://www.gnu.org/licenses/>.       *
 ******************************************************************************/

#ifndef RQT_MULTIPLOT_PLUGIN_H
#define RQT_MULTIPLOT_PLUGIN_H

#include <vector>
#include <boost/concept_check.hpp>

#include <QFrame>
#include <QGridLayout>
#include <QWidget>

#include <ros/ros.h>

#include <rqt_gui_cpp/plugin.h>

#include <rqt_multiplot/plot_widget.h>

#include <ui_multiplot_plugin.h>

namespace rqt_multiplot {

class MultiplotPlugin :
  public rqt_gui_cpp::Plugin {
Q_OBJECT
public:
  MultiplotPlugin();
  
  void setNumPlots(size_t numRows, size_t numColumns);
  void setBackgroundColor(const QColor& color);
  
  void initPlugin(qt_gui_cpp::PluginContext& context);
  void shutdownPlugin();
  void saveSettings(qt_gui_cpp::Settings& plugin_settings,
    qt_gui_cpp::Settings& instance_settings) const;
  void restoreSettings(const qt_gui_cpp::Settings& plugin_settings,
    const qt_gui_cpp::Settings& instance_settings);
  
  void run();
  void pause();
  void clear();

private:
  typedef boost::shared_ptr<PlotWidget> PlotWidgetPtr;
  
  Ui::multiplot_plugin ui_;
  QWidget* widget_;
  QGridLayout* layout_;
  
  std::vector<std::vector<PlotWidgetPtr> > plots_;

private slots:
  void spinBoxRowsValueChanged(int value);
  void spinBoxColumnsValueChanged(int value);
  
  void runClicked();
  void pauseClicked();
  void clearClicked();
};

};

#endif