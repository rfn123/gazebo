/*
 * Copyright 2014 Open Source Robotics Foundation
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

#ifndef _GAZEBO_DARTUNIVERSALJOINT_HH_
#define _GAZEBO_DARTUNIVERSALJOINT_HH_

#include "gazebo/physics/UniversalJoint.hh"
#include "gazebo/physics/dart/DARTJoint.hh"
#include "gazebo/util/system.hh"

namespace gazebo
{
  namespace physics
  {
    /// \brief A universal joint.
    class GAZEBO_VISIBLE DARTUniversalJoint : public UniversalJoint<DARTJoint>
    {
      /// \brief Constructor.
      /// \param[in] _parent Pointer to the Link that is the joint' parent
      public: DARTUniversalJoint(BasePtr _parent);

      /// \brief Destuctor.
      public: virtual ~DARTUniversalJoint();

      // Documentation inherited.
      public: virtual void Load(sdf::ElementPtr _sdf);

      // Documentation inherited.
      public: virtual void Init();

      // Documentation inherited
      public: virtual ignition::math::Vector3d GetAnchor(
                  unsigned int _index) const;

      // Documentation inherited
      public: virtual ignition::math::Vector3d GetGlobalAxis(
                  unsigned int _index) const;

      // Documentation inherited
      public: virtual void SetAxis(unsigned int _index,
                  const ignition::math::Vector3d &_axis);

      // Documentation inherited
      public: virtual ignition::math::Angle GetAngleImpl(
                  unsigned int _index) const;

      // Documentation inherited
      public: virtual double GetVelocity(unsigned int _index) const;

      // Documentation inherited
      public: virtual void SetVelocity(unsigned int _index, double _vel);

      // Documentation inherited
      public: virtual void SetMaxForce(unsigned int _index, double _force);

      // Documentation inherited
      public: virtual double GetMaxForce(unsigned int _index);

      // Documentation inherited
      protected: virtual void SetForceImpl(unsigned int _index, double _effort);

      /// \brief Universal joint of DART
      protected: dart::dynamics::UniversalJoint *dtUniveralJoint;
    };
  }
}
#endif
