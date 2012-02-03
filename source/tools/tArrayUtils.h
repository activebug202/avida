/*
 *  tArrayUtils.h
 *  Avida
 *   from ThinkTank
 *
 *  Created by David on 11/19/06.
 *  Copyright 2006,2008 David Michael Bryson. All rights reserved.
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

#ifndef tArrayUtils_h
#define tArrayUtils_h

template<typename T> class tArray;


class tArrayUtils
{
private:
  static const int QUICKSORT_THRESHOLD = 10;
  
  tArrayUtils(); // @not_implemented
  tArrayUtils(const tArrayUtils&); // @not_implemented
  tArrayUtils& operator=(const tArrayUtils&); // @not_implemented


public:
  
  template<typename T> inline static void QSort(tArray<T>& array) { QSort(array, 0, array.GetSize() - 1); }
  template<typename T> static void QSort(tArray<T>& array, int begin, int end)
  {
    if (end < begin) return;
    
    if (begin - end <= QUICKSORT_THRESHOLD) {
      ISort(array, begin, end);
      return;
    }
    
    T pivot = array[begin];
    int l = begin + 1;
    int r = end;
    
    while (l != r - 1) {
      if (array[l] > pivot)
        l++;
      else
        array.Swap(l, r--);
    }
    
    if (array[l] > pivot && array[r] > pivot) {
      l = r + 1;
    } else if (array[l] > pivot && array[r] <= pivot) {
      l++; r--;
    } else if (array[l] <= pivot && array[r] > pivot) {
      array.Swap(l++, r--);
    } else {
      r = l - 1;
    }
    
    array.Swap(r--, begin);
    QSort(array, begin, r);
    QSort(array, l, end);
  }
  
  
  
  
    
  template<typename T> inline static void ISort(tArray<T>& array) { ISort(array, 0, array.GetSize() - 1); }
  template<typename T> static void ISort(tArray<T>& array, int begin, int end)
  {
    T value;
    int j;
    
    // for each entry
    for (int i = begin + 1; i <= end; i++) {
      // insert into array starting from the end of our sub-array
      value = array[i];
      j = i - 1;
      while (j >= begin && array[j] < value) {
        array[j + 1] = array[j];
        j--;
      }
      array[j + 1] = value;
    }
  }


};

#endif
