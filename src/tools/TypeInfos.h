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

#ifndef TYPEINFOS_H_
#define TYPEINFOS_H_


template<typename T> struct TypeInfos;
//{
//private:
//	static std::string GetType(){return "Undefined !";}
//};
template<> struct TypeInfos<signed char>
{
	static std::string GetType(){return "signed char";}
};
template<> struct TypeInfos<unsigned char>
{
	static std::string GetType(){return "unsigned char";}
};
template<> struct TypeInfos<signed short>
{
	static std::string GetType(){return "signed short";}
};
template<> struct TypeInfos<unsigned short>
{
	static std::string GetType(){return "unsigned short";}
};
template<> struct TypeInfos<signed int>
{
	static std::string GetType(){return "signed int";}
};
template<> struct TypeInfos<unsigned int>
{
	static std::string GetType(){return "unsigned int";}
};
template<> struct TypeInfos<signed long>
{
	static std::string GetType(){return "signed long";}
};
template<> struct TypeInfos<unsigned long>
{
	static std::string GetType(){return "unsigned long";}
};
template<> struct TypeInfos<float>
{
	static std::string GetType(){return "float";}
};
template<> struct TypeInfos<double>
{
	static std::string GetType(){return "double";}
};




#endif /*TYPEINFOS_H_*/
