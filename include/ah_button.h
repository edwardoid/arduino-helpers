// 	This program is free software: you can redistribute it and/or modify
// 	it under the terms of the GNU General Public License as published by
// 	the Free Software Foundation, either version 3 of the License, or
// 	(at your option) any later version.
// 
// 	This program is distributed in the hope that it will be useful,
// 	but WITHOUT ANY WARRANTY; without even the implied warranty of
// 	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// 	GNU General Public License for more details.
// 
// 	You should have received a copy of the GNU General Public License
// 	along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef AH_BUTTON_H
#define AH_BUTTON_H

#include "ah_types.h"

namespace ah
{
	struct Button
	{
		PIN pin;
		STATE state;
		
		void init(PIN num)
		{
			pin = num;
			pinMode(pin, INPUT);
			state = digitalRead(pin);
		}
		
		bool stateChanged()
		{
			STATE current = digitalRead(pin);
			if(current != state)
			{
				delay(10);
				current = digitalRead(pin);
				bool pressed = (current != state);
				state = current;
				return pressed;
			}
			return false;
		}
		
	};
}

#endif // AH_BUTTON_H