/*
 * SimpleStats.cpp
 *
 * (c) 2014 Sofian Audry -- info(@)sofianaudry(.)com
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

#include "SimpleStats.h"

SimpleStats::SimpleStats(real startMean, real startVar) {
  reset(startMean, startVar);
}

void SimpleStats::reset(real startMean, real startVar) {
  _mean = startMean;
  _mean2 = startVar + sq(_mean);
  _nSamples = 0;
//  _min = FLT_MAX;
//  _max = -FLT_MAX;
}

real SimpleStats::update(real value) {
  if (_nSamples == ULONG_MAX)
    _nSamples = (ULONG_MAX / 4) * 3; // simple trick that makes sure we don't overflow

  // Add one to number of samples
  _nSamples++;

  // Update mean and mean2
  real prop = (real)(_nSamples-1) / (real)_nSamples;
  _mean  = _mean  * prop + value     / _nSamples;
  _mean2 = _mean2 * prop + sq(value) / _nSamples;

  // Update min and max
//  _min = min(_min, value);
//  _max = max(_max, value);

  return _mean;
}

real SimpleStats::var() const {
  real v = (_mean2 - sq(_mean));
  return max(v, (real)0); // make sure the result is >= 0
}
