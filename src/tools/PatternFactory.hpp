/***********************************************************************

This file is part of the GilViewer project source files.

GilViewer is an open source 2D viewer (raster and vector) based on Boost
GIL and wxWidgets. GilViewer is distributed under the CeCILL-B licence. 
See Licence_CeCILL-B_V1-en.txt or http://www.cecill.info for more details.


Homepage: 

	http://launchpad.net/gilviewer
	
Copyright:
	
	Institut Geographique National (2009)

Authors: 

	Olivier Tournaire, Adrien Chauve

	
	

This software is governed by the CeCILL-B license under French law and
abiding by the rules of distribution of free software.  You can  use, 
modify and/ or redistribute the software under the terms of the CeCILL-B
license as circulated by CEA, CNRS and INRIA at the following URL
"http://www.cecill.info". 

As a counterpart to the access to the source code and  rights to copy,
modify and redistribute granted by the license, users are provided only
with a limited warranty  and the software's author,  the holder of the
economic rights,  and the successive licensors  have only  limited
liability. 

In this respect, the user's attention is drawn to the risks associated
with loading,  using,  modifying and/or developing or reproducing the
software by the user in light of its specific status of free software,
that may mean  that it is complicated to manipulate,  and  that  also
therefore means  that it is reserved for developers  and  experienced
professionals having in-depth computer knowledge. Users are therefore
encouraged to load and test the software's suitability as regards their
requirements in conditions enabling the security of their systems and/or 
data to be ensured and,  more generally, to use and operate it in the 
same conditions as regards security. 

The fact that you are presently reading this means that you have had
knowledge of the CeCILL-B license and that you accept its terms.
 
***********************************************************************/

#ifndef PATTERNFACTORY_HPP_
#define PATTERNFACTORY_HPP_

#include <map>
#include <string>
#include <stdexcept>

#include <boost/function.hpp>

/**
* @brief Classe de Factory.
*
* Implémentation d'une factory très simple à partir de "Modern C++ Design" d'Alexandrescu.
* (simple = AssocMap non opimisée, pas de gestionnaire d'erreur... à améliorer !)
* A noter l'utilisation de boost::function pour pouvoir récupérer le résultat d'un bind comme un creator,
* ce qui n'est pas possible directement avec un <TAbstractProduct* (*) () classique.
*
*/

template
<
	class TAbstractProduct,
	typename TIdentifierType = std::string,
	typename TProductCreator = boost::function<TAbstractProduct* ()>
>
class PatternFactory
{

	public:
		bool Register(const TIdentifierType& id, TProductCreator creator)
		{
			return associations_.insert( typename AssocMapType::value_type(id, creator) ).second;
		}

		bool Unregister(const TIdentifierType& id)
		{
			return associations_.erase(id) == 1;
		}

		virtual TAbstractProduct* createObject(const TIdentifierType& id)
		{
			typename AssocMapType::const_iterator i = associations_.find(id);
			if(i != associations_.end())
			{
				return (i->second)();
			}
			throw std::logic_error("Unknown object type passed to factory !\n");
		}

	private:
		typedef std::map<TIdentifierType, TProductCreator> AssocMapType;
		AssocMapType associations_;

};

#endif /* PATTERNFACTORY_HPP_ */
