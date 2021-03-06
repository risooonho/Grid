/*
Grid
entity::Grenade.cpp

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

#include "game/entities/Grenade.hpp"
#include "game/entities/ShockWave.hpp"
#include "game/entities/Shot.hpp"
#include "game/renderers/RenderImage.hpp"
#include "game/GameUpdate.hpp"
#include "game/Sound.hpp"

#include "utility/ResourceManager.hpp"

using namespace util;

namespace grid
{
namespace entity
{
    Grenade::Grenade(int shooterID, int ID)
    {
        m_shooterID = shooterID;
        m_remainingTime = 2;

        Physics * phys = new Physics(new FrictionModel(0.25, 4));
        addComponent(phys);

        sf::Image & grenadeImg = resources::getImage("grenade");
        grenadeImg.SetSmooth(false);
        RenderImage * r = new RenderImage(RP_EVENTS, grenadeImg);
        r->setScale(0.5f / GAME_TILES_SIZE);
        r->setBindScale(false);
        setRenderer(r);

        setBoundingBox(new AxisAlignedBB(-0.2, -0.2, 0.2, 0.2));
    }

    void Grenade::updateMe(GameUpdate & up)
    {
        m_remainingTime -= up.delta;
        rotation += up.delta * m_remainingTime;
        if(m_remainingTime <= 0)
            invalidate();
    }

    void Grenade::onDestruction(GameUpdate & up)
    {
        up.level->spawnEntity(new entity::ShockWave(0.3, 5.0, 12, sf::Color(255,255,0)), pos);
        Sound::instance().playSound("explosion2", sf::Randomizer::Random(0.8f, 1.2f), 100, pos);

        float step = 0.3f;
        float off = sf::Randomizer::Random(0.f, step);

        for(float t = -M_PI + off; t < M_PI + off; t += step)
        {
            Vector2f v(cos(t), sin(t));
            entity::Shot * shot = new entity::Shot(m_shooterID);
            shot->speed = 20.f * v;
            shot->pos = pos;
            shot->team = team;
            up.level->spawnEntity(shot);
        }
    }

    util::AxisAlignedBB * Grenade::getBoundingBox()
    {
        return &( m_boundingBox->set(-0.2, -0.2, 0.2, 0.2).offset(pos.x, pos.y) );
    }

    /*
        Serialization
    */

    void Grenade::serialize(std::ostream & os)
    {
        Entity::serialize(os);

        util::serialize(os, m_shooterID);
        util::serialize(os, m_remainingTime);
    }

    void Grenade::unserialize(std::istream & is) throw(GameException)
    {
        Entity::unserialize(is);

        util::unserialize(is, m_shooterID);
        util::unserialize(is, m_remainingTime);
    }

} // namespace entity
} // namespace grid

