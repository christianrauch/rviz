// Copyright (c) 2012, Willow Garage, Inc.
// Copyright (c) 2017, Open Source Robotics Foundation, Inc.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//    * Redistributions of source code must retain the above copyright
//      notice, this list of conditions and the following disclaimer.
//
//    * Redistributions in binary form must reproduce the above copyright
//      notice, this list of conditions and the following disclaimer in the
//      documentation and/or other materials provided with the distribution.
//
//    * Neither the name of the copyright holder nor the names of its
//      contributors may be used to endorse or promote products derived from
//      this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.


#ifndef RVIZ_COMMON__PROPERTIES__SPLITTER_HANDLE_HPP_
#define RVIZ_COMMON__PROPERTIES__SPLITTER_HANDLE_HPP_

#include <QWidget>

#include "rviz_common/visibility_control.hpp"

class QTreeView;

namespace rviz_common
{
namespace properties
{

/// Provides a sliding column separator between widgets.
/**
 * A tall skinny invisible widget providing left-right sliding column separator
 * adjustment for a two-column QTreeView via mouse drags.
 * Shows splitter cursor when mouse hovers over it.
 * Uses event filtering to catch resize events for the parent.
 */
class RVIZ_COMMON_PUBLIC SplitterHandle : public QWidget
{
  Q_OBJECT

public:
  explicit SplitterHandle(QTreeView * parent = 0);

  /// Set the ratio of the parent's left column to the parent widget width.
  void setRatio(float ratio);

  /// Get the ratio of the parent's left column to the parent widget width.
  float getRatio();

  /// Catch resize events sent to parent to update splitter's geometry.
  /**
   * Always returns false.
   */
  bool eventFilter(QObject * event_target, QEvent * event) override;

  void setColor(QColor color) {color_ = color; update();}

  QColor getColor() const {return color_;}

protected:
  void mousePressEvent(QMouseEvent * event) override;

  void mouseMoveEvent(QMouseEvent * event) override;

  void paintEvent(QPaintEvent * event) override;

private:
  /// Update the parent's column widths and this splitter's geometry.
  void updateGeometry();

  QTreeView * parent_;
  int x_press_offset_;

  /// The ratio of the first column width to the entire widget width.
  /**
   * Preserved during parent widget resize.
   */
  float first_column_size_ratio_;
  QColor color_;
};

}  // namespace properties
}  // namespace rviz_common

#endif  // RVIZ_COMMON__PROPERTIES__SPLITTER_HANDLE_HPP_
