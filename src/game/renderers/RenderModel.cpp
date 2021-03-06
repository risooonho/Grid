/*
Grid
RenderModel.cpp

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

#include "game/renderers/RenderModel.hpp"
#include "game/base/Entity.hpp"

namespace grid
{
    void RenderModel::update()
    {
    }

    void RenderModel::setBlendMode(sf::Blend::Mode mode)
    {
        // TODO model : setBlendMode
    }

    void RenderModel::setColor(const sf::Color & color)
    {
        m_model->setColor(color);
    }

    void RenderModel::render(Graphics & gfx)
    {
        m_model->setPosition(r_entity->pos);
        m_model->setRotation(-util::toDegrees(r_entity->rotation));
        m_model->setScale(r_entity->scale);

        m_model->render(gfx);

        //renderBoundingBox(gfx);
    }

} // namespace grid

