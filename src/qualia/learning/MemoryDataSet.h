/*
 * MemoryDataSet.h
 *
 * (c) 2013 Sofian Audry -- info(@)sofianaudry(.)com
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef MEMORYDATASET_H_
#define MEMORYDATASET_H_

#include "DataSet.h"
#include <cstring>

// A DataSet that is fully loaded into memory.
class MemoryDataSet: public DataSet {
public:
  real* data;

  MemoryDataSet(DataSet* dataSet);
  virtual ~MemoryDataSet();

  // To be called before training. Should allocate example, among other things.
  virtual void init();

  // To be called before every episode.
  virtual void reset();

  // Sets this->example to given index t.
  virtual void setExample(int t);
};

#endif /* MEMORYDATASET_H_ */
