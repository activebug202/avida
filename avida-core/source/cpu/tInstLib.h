/*
 *  tInstLib.h
 *  Avida
 *
 *  Called "tInstLib.hh" prior to 6/4/05.
 *  Copyright 1999-2011 Michigan State University. All rights reserved.
 *
 *
 *  This file is part of Avida.
 *
 *  Avida is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License
 *  as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
 *
 *  Avida is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License along with Avida.
 *  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef tInstLib_h
#define tInstLib_h

#ifndef cString_h
#include "cString.h"
#endif
#ifndef cInstLib_h
#include "cInstLib.h"
#endif
#ifndef tInstLibEntry_h
#include "tInstLibEntry.h"
#endif


template <class MethodType> class tInstLib : public cInstLib
{
private:
  const tInstLibEntry<MethodType>* m_entries;
  cString* m_nopmod_names;
  const int* m_nopmods;
  const MethodType* m_functions;

public:
  tInstLib(int size, const tInstLibEntry<MethodType>* entries, cString* nopmod_names, const int* nopmods,
           const MethodType* functions, int def, int null_inst)
  : cInstLib(size, def, null_inst), m_entries(entries), 
    m_nopmod_names(nopmod_names),
    m_nopmods(nopmods),
    m_functions(functions)
  {
    // Fill out cInstLib::m_namemap dictionary with instruction name to entry index mappings
    for(int i = 0; i < m_size; i++) m_namemap.Set((const char*)m_entries[i].GetName(), i);
  }
  
  const MethodType* GetFunctions() const { return m_functions; } 

  const cInstLibEntry& Get(int i) const { assert(i < m_size); return m_entries[i]; }


  
  const cString& GetNopName(const unsigned int id) { return m_nopmod_names[id]; }  
  int GetNopMod(const unsigned int id) { return m_nopmods[id]; }
  int GetNopMod(const Instruction& inst) { return GetNopMod(inst.GetOp()); }
};

#endif
