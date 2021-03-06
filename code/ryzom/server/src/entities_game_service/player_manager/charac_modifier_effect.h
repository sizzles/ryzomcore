// Ryzom - MMORPG Framework <http://dev.ryzom.com/projects/ryzom/>
// Copyright (C) 2010  Winch Gate Property Limited
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Affero General Public License as
// published by the Free Software Foundation, either version 3 of the
// License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Affero General Public License for more details.
//
// You should have received a copy of the GNU Affero General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.



#ifndef RY_CHARAC_MODIFIER_EFFECT_H
#define RY_CHARAC_MODIFIER_EFFECT_H


#include "game_share/characteristics.h"

#include "phrase_manager/s_effect.h"


/**
 * Effect class for characteristics buff / debuff
 * \author Alain Saffray
 * \author Nevrax France
 * \date 2003
 */
class CCharacteristicModifierEffect : public CSEffect
{
public:
	///\ctor
	CCharacteristicModifierEffect(	const TDataSetRow & creatorRowId,
									const TDataSetRow & targetRowId,
									EFFECT_FAMILIES::TEffectFamily family,
									uint32 endDate,
									uint8 power,
									CHARACTERISTICS::TCharacteristics charac,
									sint32 modifier)
		:CSEffect(creatorRowId, targetRowId, family, false, 0, power),
		_EndDate(endDate),
		_AffectedCharac(charac),
		_Modifier(modifier)
	{}

	/**
	 *  return true if it is time to update the effect. It modifies the next update of the effect
	 */
	virtual bool isTimeToUpdate();

	/**
	 * apply the effects of the... effect
	 * \param updateFlag is a flag telling which effect type has been already processed for an entity. An effect should set to 1 the bit corresponding to its effect family
	 *									if the effect does anything in it's update method (to manage effects stacking)
	 * \return true if the effect ends and must be removed
	 */
	virtual bool update( uint32 & updateFlag );

	/// callback called when the effect is actually removed
	virtual void removed();

	/// set the effect name
	inline void effectName(const std::string &str) { _EffectName = str; }
	/// get the effect name
	inline const std::string &effectName() { return _EffectName; }

private:
	/// effect end date
	NLMISC::TGameCycle		_EndDate;

	/// affected score
	CHARACTERISTICS::TCharacteristics _AffectedCharac;

	/// "name" of the effect, used for client chat messages
	std::string				_EffectName;

	/// the value added to the modifier (<0)
	sint32					_Modifier;
};
#endif // RY_CHARAC_MODIFIER_EFFECT_H

/* End of charac_modifier_effect.h */
