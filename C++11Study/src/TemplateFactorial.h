/*
 * TemplateFactorial.h
 *
 *  Created on: 13-11-2013
 *      Author: mateusz
 */

#ifndef TEMPLATEFACTORIAL_H_
#define TEMPLATEFACTORIAL_H_


template<int total, int number>
struct TemplateFactorial
{
	enum	{ value = (TemplateFactorial<total * number, number-1>::value) };
};

// czêsciowa specjalizacja szablonu
template<int total>
struct TemplateFactorial<total, 2>
{
	enum	{ value = total * 2 };
};


#endif /* TEMPLATEFACTORIAL_H_ */
