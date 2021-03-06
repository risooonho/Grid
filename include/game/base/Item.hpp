/*
Grid
Item.hpp

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

#ifndef ITEM_HPP_INCLUDED
#define ITEM_HPP_INCLUDED

#include "common.hpp"

#include "game/base/Message.hpp"
#include "game/base/GameObject.hpp"
#include "game/base/Renderer.hpp"

#include "game/RenderManager.hpp"
#include "game/GameException.hpp"

namespace grid
{
    class GameUpdate;
    class Inventory;
    class Level;

    enum ItemType
    {
        ITM_BALL_SHOOTER = 0,
        ITM_GRENADE_LAUNCHER,
        ITM_HEALTH_BONUS
    };

    /*
        An item is any kind of game object that can be stored in an inventory.
    */

    class Item : public GameObject
    {
    protected :

        // The inventory wich contains the item (owned by an entity).
        // If NULL, the item may be dropped.
        Inventory * r_inventory;
        int m_inventoryPosition;

        // Rendering the item
        Renderer * m_renderer;

    public :

        Item(int ID = -1) : GameObject(ID)
        {
            r_inventory = NULL;
            m_renderer = NULL;
            m_inventoryPosition = 0;
        }

        virtual ~Item()
        {
            if(m_renderer != NULL)
                delete m_renderer;
        }

        inline void setInventory(Inventory * inv) { r_inventory = inv; }
        inline void setInventoryPosition(int x) { m_inventoryPosition = x; }
        inline int getInventoryPosition() const { return m_inventoryPosition; }

        // Called when the item is picked.
        // level can be used for instant items to spawn some graphics entities.
        virtual void onPick(Entity * owner, Level * level = NULL) {}

        // Called when the item gains inventory's focus
        virtual void onSelect() {}

        // Called when the item loses inventory's focus
        virtual void onUnselect() {}

        void setRenderer(Renderer * r)
        {
            if(m_renderer != NULL)
                delete m_renderer;
            m_renderer = r;
        }

        // Creates the renderer of the item associated to its dropped state
        virtual Renderer * createDroppedRenderer() = 0;

        Entity * getOwner() const;

        // True if the item performs an action on pick and then disappear.
        // It may work even if the owner's inventory is full or inexistent.
        // Example : instant healing bonus
        // (See ItemPicker for more information about how this is performed)
        virtual bool isInstant() const { return false; }

        virtual int getType() const { return -1; }

        virtual void update(GameUpdate & up) = 0;
        virtual bool processMessage(Message & msg) = 0;
        virtual void registerRender(RenderManager & manager);

        /* Serialization */

        // General part
        static void serializeItem(std::ostream & os, Item & item);
        static Item * unserializeItem(std::istream & is) throw(GameException);

    protected :

        // Specific part (polymorphism)
        virtual void serialize(std::ostream & os);
        virtual void unserialize(std::istream & is);
    };

} // namespace grid


#endif // ITEM_HPP_INCLUDED
