﻿// Solstice Games © 2023. All Rights Reserved.

#ifndef SOLID_CONCEPTS_H
#define SOLID_CONCEPTS_H

#include "CoreMinimal.h"
#include "SolidMacros/Macros.h"
#include "PropertyTypeCompatibility.h"

namespace Solid
{
	template <typename T>
	CONSTEXPR NO_DISCARD bool IsStaticStruct()
	{
		return TModels_V<CStaticStructProvider, T>;
	}
	
	template <typename T>
	concept TStaticStructConcept = requires
	{
		requires IsStaticStruct<T>();
	}; // concept TStaticStructConcept

	template <typename T>
	concept TClassConcept = requires
	{
		requires std::is_class_v<T>;
	}; // concept TClassConcept

	template <TClassConcept T, typename FunctionType>
	concept THasFunctionConcept = requires (T* Instance, FunctionType Function)
	{
		(Instance->*Function)();
	}; // concept THasFunctionConcept

	template <typename T>
	concept TConcreteReflectionCompConcept = requires
	{
		requires IsConcreteTypeCompatibleWithReflectedType<T>();
	}; // concept TConcreteReflectionCompConcept
} // namespace Solid::Macros

#endif // SOLID_CONCEPTS_H