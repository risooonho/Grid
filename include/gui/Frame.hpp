/*
Grid
Frame.hpp

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

#ifndef FRAME_HPP_INCLUDED
#define FRAME_HPP_INCLUDED

#include "gui/WidgetContainer.hpp"

namespace gui
{
    class Frame : public WidgetContainer
    {
    public :

        Frame(int x, int y, int w, int h, WidgetContainer * parent = NULL)
        : WidgetContainer(x, y, w, h, parent)
        {}

        virtual ~Frame()
        {}

        virtual void onShow();
        virtual void onHide();

        virtual void render(sf::RenderWindow & screen);
    };

} // namespace gui


#endif // FRAME_HPP_INCLUDED
