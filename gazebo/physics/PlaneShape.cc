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

#include "gazebo/physics/Collision.hh"
#include "gazebo/physics/PlaneShape.hh"

using namespace gazebo;
using namespace physics;


//////////////////////////////////////////////////
PlaneShape::PlaneShape(CollisionPtr _parent)
  : Shape(_parent)
{
  this->AddType(PLANE_SHAPE);
  this->SetName("plane_shape");
}

//////////////////////////////////////////////////
PlaneShape::~PlaneShape()
{
}

//////////////////////////////////////////////////
void PlaneShape::Init()
{
  this->CreatePlane();
}

//////////////////////////////////////////////////
void PlaneShape::CreatePlane()
{
}

//////////////////////////////////////////////////
void PlaneShape::SetAltitude(const ignition::math::Vector3d &/*_pos*/)
{
}

//////////////////////////////////////////////////
void PlaneShape::SetNormal(const ignition::math::Vector3d &_norm)
{
  this->sdf->GetElement("normal")->Set(_norm);
  this->CreatePlane();
}

//////////////////////////////////////////////////
ignition::math::Vector3d PlaneShape::GetNormal() const
{
  return this->sdf->Get<ignition::math::Vector3d>("normal");
}

//////////////////////////////////////////////////
void PlaneShape::SetSize(const ignition::math::Vector2d &_size)
{
  this->sdf->GetElement("size")->Set(_size);
}

//////////////////////////////////////////////////
ignition::math::Vector2d PlaneShape::GetSize() const
{
  return this->sdf->Get<ignition::math::Vector2d>("size");
}

//////////////////////////////////////////////////
void PlaneShape::SetScale(const ignition::math::Vector3d &_scale)
{
  if (this->scale == _scale)
    return;

  this->scale = _scale;

  ignition::math::Vector2d size = this->GetSize() *
    ignition::math::Vector2d(_scale.X(), scale.Y());
  this->SetSize(size);
}

//////////////////////////////////////////////////
void PlaneShape::FillMsg(msgs::Geometry &_msg)
{
  _msg.set_type(msgs::Geometry::PLANE);
  msgs::Set(_msg.mutable_plane()->mutable_normal(), this->GetNormal());
  msgs::Set(_msg.mutable_plane()->mutable_size(), this->GetSize());
}

//////////////////////////////////////////////////
void PlaneShape::ProcessMsg(const msgs::Geometry &_msg)
{
  this->SetNormal(msgs::Convert(_msg.plane().normal()));
}
