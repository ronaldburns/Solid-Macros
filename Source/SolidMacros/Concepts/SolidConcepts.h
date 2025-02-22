﻿// Solstice Games © 2023. All Rights Reserved.

#ifndef SOLID_CONCEPTS_H
#define SOLID_CONCEPTS_H

#include "CoreMinimal.h"
#include "Concepts/BaseStructureProvider.h"
#include "SolidMacros/Macros.h"

namespace Solid
{
	template <typename T>
	FORCEINLINE constexpr NO_DISCARD bool IsStaticStruct()
	{
		return TModels_V<CBaseStructureProvider, T> || TModels_V<CStaticStructProvider, T>;
	}
	
	template <typename T>
	concept TStaticStructConcept = requires
	{
		requires IsStaticStruct<T>();
	}; // concept TStaticStructConcept

	template <typename T>
	FORCEINLINE constexpr NO_DISCARD bool IsStaticClass()
	{
		return TModels_V<CStaticClassProvider, T>;
	}

	template <typename T>
	concept TStaticClassConcept = requires
	{
		requires IsStaticClass<T>();
	}; // concept TStaticClassConcept

	template <typename T>
	FORCEINLINE constexpr NO_DISCARD bool IsStaticEnum()
	{
		return TIsUEnumClass<T>::Value;
	}

	template <typename T>
	concept TStaticEnumConcept = requires
	{
		requires IsStaticEnum<T>();
	}; // concept TStaticEnumConcept

	template <typename T>
	concept TClassConcept = requires
	{
		requires std::is_class_v<T>;
	}; // concept TClassConcept

	template <typename T>
	concept TIsOptionalConcept = requires
	{
		requires TIsTOptional_V<T>;
	}; // concept TIsOptionalConcept

	template<typename F, typename ...Args>
	concept TInvocableConcept = TIsInvocable<F, Args...>::Value;
	
} // namespace Solid

#endif // SOLID_CONCEPTS_H