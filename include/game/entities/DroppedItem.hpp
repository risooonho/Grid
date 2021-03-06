/*
Grid
EntityDroppedItem.hpp

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

#ifndef ENTITYDROPPEDITEM_HPP_INCLUDED
#define ENTITYDROPPEDITEM_HPP_INCLUDED

#include "game/base/Entity.hpp"
#include "game/base/Item.hpp"

namespace grid
{
namespace entity
{
    class DroppedItem : public Entity
    {
    protected :

        Item * m_item;

    public :

        DroppedItem(Item * item = NULL, int ID = -1);

        virtual ~DroppedItem()
        {
            if(m_item != NULL)
                delete m_item;
        }

        // returns the item
        // Warning : m_item is set to NULL after this !
        // Remember to free memory if the returned item is unusued.
        Item * pickItem();

        const Item * getItem() const { return m_item; }

        virtual void updateMe(GameUpdate & up);

        virtual int getType() const { return ENT_DROPPED_ITEM; }
        virtual bool isDroppedItem() const { return true; }

    protected :

        virtual void serialize(std::ostream & os);
        virtual void unserialize(std::istream & is) throw(GameException);
    };

} // namespace entity
} // namespace grid


#endif // ENTITYDROPPEDITEM_HPP_INCLUDED
