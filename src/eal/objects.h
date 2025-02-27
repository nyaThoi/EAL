/* 
 * This file is part of the Eidolon Auto Link distribution (https://github.com/AlainProvist/EAL).
 * Copyright (c) 2019 AlainProvist.
 * 
 * This program is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU General Public License as published by  
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
*/


#ifndef OBJECTS_H
#define OBJECTS_H

#include <stdio.h>
#include <vector>
#include <WTypes.h>
#include "Vector3.h"

#include "libutils.h"


struct EntityElement
{
	EntityElement* next;
	EntityElement* previous;
	u32 id;
	Entity* entity;
};

template <typename T>
struct Collection
{
	u32 unk1;
	u32 unk2;

	template <typename T>
	struct Container
	{
		T* begin;
		T* unkLink1;
		T* unkLink2;
	};

	Container<T> *container;// 8
	u32 nbElements;// c

	u8 unk3[0x1c];// 10

	std::string name;// 2c : name of the collection
};
typedef Collection<EntityElement> EntityCollection;

enum EntityCollectionType { ECT_CharaCollection, ECT_EffectColletion, ECT_DuelCollection };

struct CurrentMap
{
	u32 unk1;
	u16 unk2;// 0x4
	s16 mapID;
	std::string mapName1;// 0x8
	std::string mapName2;// 0x24
};

struct InventoryBag
{
	u32 unk1;
	u32 bagID;
	InventoryItem** begin;
	InventoryItem** end;

	u32 GetItemCount() const { return (((u32)end - (u32)begin)>>2); }
	InventoryItem* GetItem(u32 index) { return (index < GetItemCount())? begin[index] : NULL; }
};



class EudemonWindow : public AKWindow
{
public:
	u8 unk3[0x184];// 0x20
	void* unkPtr;// 0x1a4 -> have to be non 0 when using eudemon actions without selecting eudemons (will be set be selecteudemon())
	u8 unk4[0x180];// 0x1a8
	u16 currentSlotSelected;// 0x328
	u16 pm[4];// 0x32A->0x332 : 4 slots for the 4 eudemons  : pm available (to gather) (0 if no eudemon)
};


#endif // OBJECTS_H