/*
Grid
RenderItem.hpp

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

#ifndef RENDERITEM_HPP_INCLUDED
#define RENDERITEM_HPP_INCLUDED

#include "common.hpp"
#include "game/Graphics.hpp"
#include "game/renderers/RenderImage.hpp"

namespace grid
{
    class Item;

    class RenderItem : public RenderImage
    {
    protected :

        const Item * r_item;

    public :

        RenderItem(const Item * item, int pass, const sf::Image & img);

        virtual void update();
        virtual void render(Graphics & gfx);
    };

} // namespace grid

#endif // RENDERITEM_HPP_INCLUDED
