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

#ifndef RQT_MULTIPLOT_PLOT_TABLE_CONFIG_H
#define RQT_MULTIPLOT_PLOT_TABLE_CONFIG_H

#include <QColor>
#include <QObject>
#include <QVector>

#include <rqt_multiplot/PlotConfig.h>

namespace rqt_multiplot {
  class PlotTableConfig :
    public QObject {
  Q_OBJECT
  public:
    PlotTableConfig(QObject* parent, const QColor& backgroundColor =
      Qt::white, size_t numRows = 1, size_t numColumns = 1);
    ~PlotTableConfig();

    void setBackgroundColor(const QColor& color);
    const QColor& getBackgroundColor() const;
    void setNumPlots(size_t numRows, size_t numColumns);
    void setNumRows(size_t numRows);
    size_t getNumRows() const;
    void setNumColumns(size_t numColumns);
    size_t getNumColumns() const;
    PlotConfig* getPlotConfig(size_t row, size_t column) const;
    
    PlotTableConfig& operator=(const PlotTableConfig& src);
    
  signals:
    void backgroundColorChanged(const QColor& color);
    void numPlotsChanged(size_t numRows, size_t numColumns);
    void changed();
    
  private:
    QColor backgroundColor_;
    QVector<QVector<PlotConfig*> > plotConfig_;
    
  private slots:
    void plotConfigChanged();
  };
};

#endif