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

#ifndef AH_LED_H
#define AH_LED_H

#include <ah_types.h>

namespace ah
{
	struct Led
	{
		PIN pin;
		STATE state;
		void init(PIN num)
		{
			pin = num;
			pinMode(pin, OUTPUT);
			setOff();
		}
		
		void setOff()
		{
			digitalWrite(pin, LOW);
			state = LOW;
		}
		
		void setOn()
		{
			digitalWrite(pin, HIGH);
			state = HIGH;
		}
		
		void blink(unsigned long deltaT)
		{
			setOn();
			delay(deltaT);
			setOff();
			delay(deltaT);
		}
		
	};
}

#endif // AH_LED_H