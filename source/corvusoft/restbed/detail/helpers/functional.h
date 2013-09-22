/*
 * Site: restbed.corvusoft.co.uk
 * Author: Ben Crowhurst
 *
 * Copyright (c) 2013 Restbed Core Development Team and Community Contributors
 *
 * This file is part of Restbed.
 *
 * Restbed is free software: you can redistribute it and/or modify
 * it under the terms of the Lesser GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Restbed is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * Lesser GNU General Public License for more details.
 *
 * You should have received a copy of the Lesser GNU General Public License
 * along with Restbed.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _RESTBED_DETAIL_HELPER_FUNCTIONAL_H
#define _RESTBED_DETAIL_HELPER_FUNCTIONAL_H 1

//System Includes
#include <functional>

//Project Includes

//External Includes

//System Namespaces

//Project Namespaces

//External Namespaces

namespace restbed
{
    //Forward Declarations
    
    namespace detail
    {
        //Forward Declarations

        namespace helpers
        {
            //Forward Declarations
            
            class Functional
            {
                public:
                    //Friends
                    
                    //Definitions
 
                    //Constructors
                    
                    //Functionality
                    template< typename Type, typename... Arguments >
                    static std::size_t get_address( std::function< Type( Arguments... ) > function )
                    {
                        typedef Type( function_decl )( Arguments... );

                        function_decl** ptr = function.template target< function_decl* >( );

                        size_t address = ( ptr not_eq nullptr ) ? ( size_t ) *ptr : 0;
                        
                        return address;
                    }

                    //Getters
                    
                    //Setters
                    
                    //Operators
                    
                    //Properties
                
                protected:
                    //Friends
                    
                    //Definitions
                    
                    //Constructors
                    
                    //Functionality
                    
                    //Getters
                    
                    //Setters
                    
                    //Operators
                    
                    //Properties
                    
                private:
                    //Friends
                    
                    //Definitions
                    
                    //Constructors
                    Functional( void ) = delete;
                    
                    Functional( const Functional& original ) = delete;
                    
                    virtual ~Functional( void ) = delete;

                    //Functionality
                    
                    //Getters
                    
                    //Setters
                    
                    //Operators
                    Functional& operator =( const Functional& rhs ) = delete;

                    //Properties
            };
        }
    }
}

#endif  /* _RESTBED_DETAIL_HELPER_FUNCTIONAL_H */