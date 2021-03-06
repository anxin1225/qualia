/*
 * MovingAverage.h
 *
 * Tool for moving averages.
 *
 * This file is part of Qualia https://github.com/sofian/qualia
 *
 * (c) 2011 Sofian Audry -- info(@)sofianaudry(.)com
 * Inspired by code by Karsten Kutza
 * http://www.ip-atlas.com/pub/nap/nn-src/bpn.txt
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
#ifndef MOVINGAVERAGE_H_
#define MOVINGAVERAGE_H_

#include <qualia/core/common.h>

class MovingAverage {
public:
  float _alpha;
  real _value;

  /**
   * Constructs the moving average, starting with #startValue# as its value. The #alphaOrN# argument
   * has two options:
   * - if <= 1 then it's used directly as the alpha value
   * - if > 1 then it's used as the "number of items that are considered from the past" (*)
   * (*) Of course this is an approximation. It actually sets the alpha value to 2 / (n - 1)
   */
  MovingAverage(float alphaOrN, real startValue);
  virtual ~MovingAverage() {}

  /**
   * Resets the moving average to #startValue#.
   */
  void reset(real startValue);

  /**
   * Updates the moving average with new value #v# (also returns the current value).
   */
  real update(real v);

  /**
   * Returns the value of the moving average.
   */
  real get() const { return _value; }

};

#endif /* MOVINGAVERAGE_H_ */
