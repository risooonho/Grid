/*
Grid
Collision.hpp

Copyright (c) 2011 by Marc Gilleron, <marc.gilleron@free.fr>

This program is free software: you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by the Free
Software Foundation, either version 3 of the License, or (at your option)
any later version.

This program is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
more details.

You should have received a copy of the GNU General Public License along with
this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef COLLISION_HPP_INCLUDED
#define COLLISION_HPP_INCLUDED

#include "utility/AxisAlignedBB.hpp"

namespace grid
{
    class Entity;

    struct Collision
    {
        Entity * entity; // not null if it is an Entity collision
        util::AxisAlignedBB box;

        Collision(Entity * e, util::AxisAlignedBB b)
        : entity(e), box(b)
        {
        }
    };

} // namespace grid


#endif // COLLISION_HPP_INCLUDED
