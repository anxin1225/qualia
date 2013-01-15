/*
 * DataSet.cpp
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

#include "DataSet.h"

DataSet::DataSet()
  : nExamples(0), dim(0), example(0) {
}

DataSet::DataSet(int nExamples_, int dim_) {
  init(nExamples_, dim_);
}

void DataSet::init(int nExamples_, int dim_) {
  nExamples = nExamples_;
  dim       = dim_;
}

DataSet::~DataSet() {
}
