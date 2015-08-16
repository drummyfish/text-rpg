#ifndef LOCATION_H
#define LOCATION_H

/** \file location.h
 * 
 */

/*
  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "general.h"

class Path;

/**
 * Represents a game location.
 */

class Location: public NameableDescribableIdentifiable, public DebugSerializable
  {
    protected:
      std::vector<Path> paths;
      
    public:
      /**
       * Connects this location to another one, i.e. creates a new path and stores it in this
       * location.
       * 
       * @param name new path name
       * @param destination destination, i.e. a location this location should be connected to
       * @param length_km path length in kilometers
       * @param bidirectional if true then a symmetrical path will be created and added to
       *   destination path creating a bidirectional path, if false, only one (one-directional)
       *   path will be created
       */
      
      void create_path(std::string name, Location *destination, float length_km, bool bidirectional=true);
      unsigned int get_number_of_paths();
      virtual std::string debug_string(debug_string_flag flags=(debug_string_flag) 0);
  };
  
class Path: public NameableIdentifiable, public DebugSerializable
  {
    protected:
      Location *destination;
      float length_km;
      bool blocked;
      
    public:
      Path();    
      void set_destination(Location *destination);
      Location *get_destination();
      void set_length(float length_km);
      float get_length();
      virtual std::string debug_string(debug_string_flag flags=(debug_string_flag) 0);
  };

#endif