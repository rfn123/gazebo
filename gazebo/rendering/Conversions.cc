/*
 * Copyright (C) 2012-2014 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/
#include "gazebo/rendering/Conversions.hh"

using namespace gazebo;
using namespace rendering;

//////////////////////////////////////////////////
Ogre::ColourValue Conversions::Convert(const common::Color &_color)
{
  return Ogre::ColourValue(_color.r, _color.g, _color.b, _color.a);
}

//////////////////////////////////////////////////
common::Color Conversions::Convert(const Ogre::ColourValue &_clr)
{
  return common::Color(_clr.r, _clr.g, _clr.b, _clr.a);
}

//////////////////////////////////////////////////
Ogre::Vector3 Conversions::Convert(const ignition::math::Vector3d &v)
{
  return Ogre::Vector3(v.X(), v.Y(), v.Z());
}

//////////////////////////////////////////////////
ignition::math::Vector3d Conversions::Convert(const Ogre::Vector3 &v)
{
  return ignition::math::Vector3d(v.x, v.y, v.z);
}

//////////////////////////////////////////////////
Ogre::Quaternion Conversions::Convert(const ignition::math::Quaterniond &_v)
{
  return Ogre::Quaternion(_v.W(), _v.X(), _v.Y(), _v.Z());
}

//////////////////////////////////////////////////
ignition::math::Quaterniond Conversions::Convert(const Ogre::Quaternion &_v)
{
  return ignition::math::Quaterniond(_v.w, _v.x, _v.y, _v.z);
}
