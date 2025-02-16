// Copyright (c) 2009, Willow Garage, Inc.
// Copyright (c) 2018, Bosch Software Innovations GmbH.
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


#ifndef RVIZ_DEFAULT_PLUGINS__DISPLAYS__MARKER__MARKERS__POINTS_MARKER_HPP_
#define RVIZ_DEFAULT_PLUGINS__DISPLAYS__MARKER__MARKERS__POINTS_MARKER_HPP_

#include <memory>

#include "rviz_rendering/objects/point_cloud.hpp"

#include "rviz_default_plugins/displays/marker/markers/marker_base.hpp"
#include "rviz_default_plugins/visibility_control.hpp"

namespace Ogre
{
class SceneNode;
}  // namespace Ogre

namespace rviz_default_plugins
{
namespace displays
{
namespace markers
{

class RVIZ_DEFAULT_PLUGINS_PUBLIC PointsMarker : public MarkerBase
{
public:
  using SharedPtr = std::shared_ptr<PointsMarker>;

  PointsMarker(
    MarkerCommon * owner, rviz_common::DisplayContext * context, Ogre::SceneNode * parent_node);

  ~PointsMarker() override;

  void setHighlightColor(float red, float green, float blue);

protected:
  void onNewMessage(
    const MarkerConstSharedPtr & old_message, const MarkerConstSharedPtr & new_message) override;
  void transformAndSetVisibility(
    const MarkerConstSharedPtr & new_message,
    Ogre::Vector3 & position,
    Ogre::Vector3 & scale,
    Ogre::Quaternion & orientation);
  void setRenderModeAndDimensions(const MarkerConstSharedPtr & new_message, Ogre::Vector3 & scale);
  void addPointsFromMessage(const MarkerConstSharedPtr & new_message);

  rviz_rendering::PointCloud * points_;
};

}  // namespace markers
}  // namespace displays
}  // namespace rviz_default_plugins

#endif  // RVIZ_DEFAULT_PLUGINS__DISPLAYS__MARKER__MARKERS__POINTS_MARKER_HPP_
