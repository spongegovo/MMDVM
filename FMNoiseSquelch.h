/*
 *   Copyright (C) 2020 by Jonathan Naylor G4KLX
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#if !defined(FMNOISESQUELCH_H)
#define  FMNOISESQUELCH_H

#include "Config.h"

class CFMNoiseSquelch {
public:
  CFMNoiseSquelch();

  void setParams(uint8_t highThreshold, uint8_t lowThreshold);
  
  bool process(q15_t sample);

  void reset();

private:
  q31_t    m_highThreshold;
  q31_t    m_lowThreshold;
  uint16_t m_count;
  q31_t    m_q0;
  q31_t    m_q1;
  bool     m_state;
  uint8_t  m_validCount;
  uint8_t  m_invalidCount;
};

#endif
