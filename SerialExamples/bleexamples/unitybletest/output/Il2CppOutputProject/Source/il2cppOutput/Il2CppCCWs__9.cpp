#include "pch-cpp.hpp"




#include "vm/CachedCCWBase.h"
#include "utils/New.h"


struct IEqualityComparer_1_tDBFC8496F14612776AF930DBF84AFE7D06D1F0E9;
struct KeyCollection_t3C85F0FB2361623F947E239ECB8C6EA2836972E6;
struct KeyCollection_t1DD9DA01E8F917158E0E796B8B9237D890B32700;
struct KeyCollection_tD884580AC512BF42FF32239C9DE7F0DE9EB48784;
struct KeyCollection_t7032C42BDB9F81A00537C262F53859F054515A62;
struct KeyCollection_tA56468ED3446803A019F31D8B16B398E4DB1DA1C;
struct KeyCollection_t4BECA2454F6C37913B123130EABAEF55D04418EB;
struct KeyCollection_t66E188B36DF8E1A23EBDA7253CDCE978CD3EF298;
struct ValueCollection_tF72C67744D53CFCECA230FB0E8403D814C75987A;
struct ValueCollection_t2458D1DC649FD3CF095F724C3EC92E16FA46982B;
struct ValueCollection_t70917A76D89E03EC014468EBBD53500D70BA139D;
struct ValueCollection_t610505C1353EB2B43336B80F2791B3368126589C;
struct ValueCollection_tEE080CCD7CB382814B0F8287EEBDC6F426847938;
struct ValueCollection_tAB3DB7C2EE181E2BB1F09C42265216010153EB17;
struct ValueCollection_t95D69F17F87935E5166EE0E3C174BB8A8F051F5B;
struct EntryU5BU5D_t27CBB347FB12E799B62603B0DDDE6FF3678117EE;
struct EntryU5BU5D_t1D278BBD8CED6790AF7799AA4CFD47335ABAEF14;
struct EntryU5BU5D_t73E445E7B194CEF4B3E10F383B3695EA92AD9907;
struct EntryU5BU5D_t20232555B01299E50C6D0216F01265BFAE9192BD;
struct EntryU5BU5D_t4D1D401ABCF75A70C628D864C667E50BD5FDEA70;
struct EntryU5BU5D_t1275B8CF5846D24D6A01E0B85A2DF993D2A6BD88;
struct EntryU5BU5D_t6E8F51999B5C2D1A5E09B1963CF042E7B5CAA500;
struct Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C;

struct IBindableIterator_t63CCD2268CEE8AFAB68518869D47C5BDAF72962F;
struct IIterator_1_t88F3ACE96E95F4306BB1B6297F9035FF9344CFCD;
struct IMapView_2_t039A6D425D93544903087E0132BAA7C4C4AA8B1E;


IL2CPP_EXTERN_C_BEGIN
IL2CPP_EXTERN_C_END

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
struct NOVTABLE IIterable_1_tC77B5EDDE910309A730C993BC41B3E9EEBF99F53 : Il2CppIInspectable
{
	static const Il2CppGuid IID;
	virtual il2cpp_hresult_t STDCALL IIterable_1_First_mFD302876C9FFDC28D63D8F32AF019F65A059E930(IIterator_1_t88F3ACE96E95F4306BB1B6297F9035FF9344CFCD** comReturnValue) = 0;
};
struct NOVTABLE IMapView_2_t039A6D425D93544903087E0132BAA7C4C4AA8B1E : Il2CppIInspectable
{
	static const Il2CppGuid IID;
	virtual il2cpp_hresult_t STDCALL IMapView_2_Lookup_m24D5938C10FB85A7D76DC9B5F859EC1E9ABCF366(int32_t ___0_key, bool* comReturnValue) = 0;
	virtual il2cpp_hresult_t STDCALL IMapView_2_get_Size_mA24B602FF8F1560E6EEB4FE3A8867F97683528F3(uint32_t* comReturnValue) = 0;
	virtual il2cpp_hresult_t STDCALL IMapView_2_HasKey_m82681036A649B64BA426284FF5EDA26A39C8732F(int32_t ___0_key, bool* comReturnValue) = 0;
	virtual il2cpp_hresult_t STDCALL IMapView_2_Split_m73E25E3D118B7DA54DC9B4E39FCD9021A32E97C7(IMapView_2_t039A6D425D93544903087E0132BAA7C4C4AA8B1E** ___0_first, IMapView_2_t039A6D425D93544903087E0132BAA7C4C4AA8B1E** ___1_second) = 0;
};
struct NOVTABLE IMap_2_t873A5BC95B85361B068A4BCF2679E8C7F8891AD1 : Il2CppIInspectable
{
	static const Il2CppGuid IID;
	virtual il2cpp_hresult_t STDCALL IMap_2_Lookup_m5E7D704F83ECD8DA321C9D5EAB15FD81D0F508F6(int32_t ___0_key, bool* comReturnValue) = 0;
	virtual il2cpp_hresult_t STDCALL IMap_2_get_Size_m3B2434A5F22F58C902D9B0461F2A3AA7819B6D08(uint32_t* comReturnValue) = 0;
	virtual il2cpp_hresult_t STDCALL IMap_2_HasKey_m60394980063C15911ACEFEC6514862CBBC7A95EA(int32_t ___0_key, bool* comReturnValue) = 0;
	virtual il2cpp_hresult_t STDCALL IMap_2_GetView_m7B7F9E15872477D63031DB0298735A3E4B0C61D8(IMapView_2_t039A6D425D93544903087E0132BAA7C4C4AA8B1E** comReturnValue) = 0;
	virtual il2cpp_hresult_t STDCALL IMap_2_Insert_mCB092C48F5BA8B47182D2C5BC9F04996C487EC78(int32_t ___0_key, bool ___1_value, bool* comReturnValue) = 0;
	virtual il2cpp_hresult_t STDCALL IMap_2_Remove_m7BCAF8AF8B7C3B565CD41332AA256849815F2E71(int32_t ___0_key) = 0;
	virtual il2cpp_hresult_t STDCALL IMap_2_Clear_mE6DBB1691EBB8FB7283A555622CDDAFBED9232C4() = 0;
};
struct NOVTABLE IBindableIterable_t257967EF5CDA5DFD63615802571892212B01796C : Il2CppIInspectable
{
	static const Il2CppGuid IID;
	virtual il2cpp_hresult_t STDCALL IBindableIterable_First_mE23AC28EC9ADCDD2688247217CF40C800E780B97(IBindableIterator_t63CCD2268CEE8AFAB68518869D47C5BDAF72962F** comReturnValue) = 0;
};
struct Dictionary_2_t4EAC15363030DFDF453F1AB77D690425033951F5  : public RuntimeObject
{
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____buckets;
	EntryU5BU5D_t27CBB347FB12E799B62603B0DDDE6FF3678117EE* ____entries;
	int32_t ____count;
	int32_t ____freeList;
	int32_t ____freeCount;
	int32_t ____version;
	RuntimeObject* ____comparer;
	KeyCollection_t3C85F0FB2361623F947E239ECB8C6EA2836972E6* ____keys;
	ValueCollection_tF72C67744D53CFCECA230FB0E8403D814C75987A* ____values;
	RuntimeObject* ____syncRoot;
};
struct Dictionary_2_tBE995FA87CE27220FD97BCC009668BA7930F425B  : public RuntimeObject
{
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____buckets;
	EntryU5BU5D_t1D278BBD8CED6790AF7799AA4CFD47335ABAEF14* ____entries;
	int32_t ____count;
	int32_t ____freeList;
	int32_t ____freeCount;
	int32_t ____version;
	RuntimeObject* ____comparer;
	KeyCollection_t1DD9DA01E8F917158E0E796B8B9237D890B32700* ____keys;
	ValueCollection_t2458D1DC649FD3CF095F724C3EC92E16FA46982B* ____values;
	RuntimeObject* ____syncRoot;
};
struct Dictionary_2_tD67DCDAF66E2D5C2520AA4035B35E6DCC259DB41  : public RuntimeObject
{
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____buckets;
	EntryU5BU5D_t73E445E7B194CEF4B3E10F383B3695EA92AD9907* ____entries;
	int32_t ____count;
	int32_t ____freeList;
	int32_t ____freeCount;
	int32_t ____version;
	RuntimeObject* ____comparer;
	KeyCollection_tD884580AC512BF42FF32239C9DE7F0DE9EB48784* ____keys;
	ValueCollection_t70917A76D89E03EC014468EBBD53500D70BA139D* ____values;
	RuntimeObject* ____syncRoot;
};
struct Dictionary_2_tBFA6A92ADF404217ADC6287258F898AC33533339  : public RuntimeObject
{
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____buckets;
	EntryU5BU5D_t20232555B01299E50C6D0216F01265BFAE9192BD* ____entries;
	int32_t ____count;
	int32_t ____freeList;
	int32_t ____freeCount;
	int32_t ____version;
	RuntimeObject* ____comparer;
	KeyCollection_t7032C42BDB9F81A00537C262F53859F054515A62* ____keys;
	ValueCollection_t610505C1353EB2B43336B80F2791B3368126589C* ____values;
	RuntimeObject* ____syncRoot;
};
struct Dictionary_2_tE07DE99BCB5707DE2E531BB2B2D5537571B26B7E  : public RuntimeObject
{
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____buckets;
	EntryU5BU5D_t4D1D401ABCF75A70C628D864C667E50BD5FDEA70* ____entries;
	int32_t ____count;
	int32_t ____freeList;
	int32_t ____freeCount;
	int32_t ____version;
	RuntimeObject* ____comparer;
	KeyCollection_tA56468ED3446803A019F31D8B16B398E4DB1DA1C* ____keys;
	ValueCollection_tEE080CCD7CB382814B0F8287EEBDC6F426847938* ____values;
	RuntimeObject* ____syncRoot;
};
struct Dictionary_2_tD5545BC5C76F0FE1D42E73713A5484EE3FC0A159  : public RuntimeObject
{
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____buckets;
	EntryU5BU5D_t1275B8CF5846D24D6A01E0B85A2DF993D2A6BD88* ____entries;
	int32_t ____count;
	int32_t ____freeList;
	int32_t ____freeCount;
	int32_t ____version;
	RuntimeObject* ____comparer;
	KeyCollection_t4BECA2454F6C37913B123130EABAEF55D04418EB* ____keys;
	ValueCollection_tAB3DB7C2EE181E2BB1F09C42265216010153EB17* ____values;
	RuntimeObject* ____syncRoot;
};
struct Dictionary_2_t01224C8DBCCFE276E97D2BF52F4D7B10D3642682  : public RuntimeObject
{
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____buckets;
	EntryU5BU5D_t6E8F51999B5C2D1A5E09B1963CF042E7B5CAA500* ____entries;
	int32_t ____count;
	int32_t ____freeList;
	int32_t ____freeCount;
	int32_t ____version;
	RuntimeObject* ____comparer;
	KeyCollection_t66E188B36DF8E1A23EBDA7253CDCE978CD3EF298* ____keys;
	ValueCollection_t95D69F17F87935E5166EE0E3C174BB8A8F051F5B* ____values;
	RuntimeObject* ____syncRoot;
};
#ifdef __clang__
#pragma clang diagnostic pop
#endif

il2cpp_hresult_t IBindableIterable_First_mE23AC28EC9ADCDD2688247217CF40C800E780B97_ComCallableWrapperProjectedMethod(RuntimeObject* __this, IBindableIterator_t63CCD2268CEE8AFAB68518869D47C5BDAF72962F** comReturnValue);
il2cpp_hresult_t IMap_2_Lookup_m5E7D704F83ECD8DA321C9D5EAB15FD81D0F508F6_ComCallableWrapperProjectedMethod(RuntimeObject* __this, int32_t ___0_key, bool* comReturnValue);
il2cpp_hresult_t IMap_2_get_Size_m3B2434A5F22F58C902D9B0461F2A3AA7819B6D08_ComCallableWrapperProjectedMethod(RuntimeObject* __this, uint32_t* comReturnValue);
il2cpp_hresult_t IMap_2_HasKey_m60394980063C15911ACEFEC6514862CBBC7A95EA_ComCallableWrapperProjectedMethod(RuntimeObject* __this, int32_t ___0_key, bool* comReturnValue);
il2cpp_hresult_t IMap_2_GetView_m7B7F9E15872477D63031DB0298735A3E4B0C61D8_ComCallableWrapperProjectedMethod(RuntimeObject* __this, IMapView_2_t039A6D425D93544903087E0132BAA7C4C4AA8B1E** comReturnValue);
il2cpp_hresult_t IMap_2_Insert_mCB092C48F5BA8B47182D2C5BC9F04996C487EC78_ComCallableWrapperProjectedMethod(RuntimeObject* __this, int32_t ___0_key, bool ___1_value, bool* comReturnValue);
il2cpp_hresult_t IMap_2_Remove_m7BCAF8AF8B7C3B565CD41332AA256849815F2E71_ComCallableWrapperProjectedMethod(RuntimeObject* __this, int32_t ___0_key);
il2cpp_hresult_t IMap_2_Clear_mE6DBB1691EBB8FB7283A555622CDDAFBED9232C4_ComCallableWrapperProjectedMethod(RuntimeObject* __this);
il2cpp_hresult_t IIterable_1_First_mFD302876C9FFDC28D63D8F32AF019F65A059E930_ComCallableWrapperProjectedMethod(RuntimeObject* __this, IIterator_1_t88F3ACE96E95F4306BB1B6297F9035FF9344CFCD** comReturnValue);
il2cpp_hresult_t IMapView_2_Lookup_m24D5938C10FB85A7D76DC9B5F859EC1E9ABCF366_ComCallableWrapperProjectedMethod(RuntimeObject* __this, int32_t ___0_key, bool* comReturnValue);
il2cpp_hresult_t IMapView_2_get_Size_mA24B602FF8F1560E6EEB4FE3A8867F97683528F3_ComCallableWrapperProjectedMethod(RuntimeObject* __this, uint32_t* comReturnValue);
il2cpp_hresult_t IMapView_2_HasKey_m82681036A649B64BA426284FF5EDA26A39C8732F_ComCallableWrapperProjectedMethod(RuntimeObject* __this, int32_t ___0_key, bool* comReturnValue);
il2cpp_hresult_t IMapView_2_Split_m73E25E3D118B7DA54DC9B4E39FCD9021A32E97C7_ComCallableWrapperProjectedMethod(RuntimeObject* __this, IMapView_2_t039A6D425D93544903087E0132BAA7C4C4AA8B1E** ___0_first, IMapView_2_t039A6D425D93544903087E0132BAA7C4C4AA8B1E** ___1_second);



struct Dictionary_2_t4EAC15363030DFDF453F1AB77D690425033951F5_ComCallableWrapper IL2CPP_FINAL : il2cpp::vm::CachedCCWBase<Dictionary_2_t4EAC15363030DFDF453F1AB77D690425033951F5_ComCallableWrapper>, IBindableIterable_t257967EF5CDA5DFD63615802571892212B01796C
{
	inline Dictionary_2_t4EAC15363030DFDF453F1AB77D690425033951F5_ComCallableWrapper(RuntimeObject* obj) : il2cpp::vm::CachedCCWBase<Dictionary_2_t4EAC15363030DFDF453F1AB77D690425033951F5_ComCallableWrapper>(obj) {}

	virtual il2cpp_hresult_t STDCALL QueryInterface(const Il2CppGuid& iid, void** object) IL2CPP_OVERRIDE
	{
		if (::memcmp(&iid, &Il2CppIUnknown::IID, sizeof(Il2CppGuid)) == 0
		 || ::memcmp(&iid, &Il2CppIInspectable::IID, sizeof(Il2CppGuid)) == 0
		 || ::memcmp(&iid, &Il2CppIAgileObject::IID, sizeof(Il2CppGuid)) == 0)
		{
			*object = GetIdentity();
			AddRefImpl();
			return IL2CPP_S_OK;
		}

		if (::memcmp(&iid, &Il2CppIManagedObjectHolder::IID, sizeof(Il2CppGuid)) == 0)
		{
			*object = static_cast<Il2CppIManagedObjectHolder*>(this);
			AddRefImpl();
			return IL2CPP_S_OK;
		}

		if (::memcmp(&iid, &IBindableIterable_t257967EF5CDA5DFD63615802571892212B01796C::IID, sizeof(Il2CppGuid)) == 0)
		{
			*object = static_cast<IBindableIterable_t257967EF5CDA5DFD63615802571892212B01796C*>(this);
			AddRefImpl();
			return IL2CPP_S_OK;
		}

		if (::memcmp(&iid, &Il2CppIMarshal::IID, sizeof(Il2CppGuid)) == 0)
		{
			*object = static_cast<Il2CppIMarshal*>(this);
			AddRefImpl();
			return IL2CPP_S_OK;
		}

		if (::memcmp(&iid, &Il2CppIWeakReferenceSource::IID, sizeof(Il2CppGuid)) == 0)
		{
			*object = static_cast<Il2CppIWeakReferenceSource*>(this);
			AddRefImpl();
			return IL2CPP_S_OK;
		}

		*object = NULL;
		return IL2CPP_E_NOINTERFACE;
	}

	virtual uint32_t STDCALL AddRef() IL2CPP_OVERRIDE
	{
		return AddRefImpl();
	}

	virtual uint32_t STDCALL Release() IL2CPP_OVERRIDE
	{
		return ReleaseImpl();
	}

	virtual il2cpp_hresult_t STDCALL GetIids(uint32_t* iidCount, Il2CppGuid** iids) IL2CPP_OVERRIDE
	{
		Il2CppGuid* interfaceIds = il2cpp_codegen_marshal_allocate_array<Il2CppGuid>(1);
		interfaceIds[0] = IBindableIterable_t257967EF5CDA5DFD63615802571892212B01796C::IID;

		*iidCount = 1;
		*iids = interfaceIds;
		return IL2CPP_S_OK;
	}

	virtual il2cpp_hresult_t STDCALL GetRuntimeClassName(Il2CppHString* className) IL2CPP_OVERRIDE
	{
		return GetRuntimeClassNameImpl(className);
	}

	virtual il2cpp_hresult_t STDCALL GetTrustLevel(int32_t* trustLevel) IL2CPP_OVERRIDE
	{
		return ComObjectBase::GetTrustLevel(trustLevel);
	}

	virtual il2cpp_hresult_t STDCALL IBindableIterable_First_mE23AC28EC9ADCDD2688247217CF40C800E780B97(IBindableIterator_t63CCD2268CEE8AFAB68518869D47C5BDAF72962F** comReturnValue) IL2CPP_OVERRIDE
	{
		return IBindableIterable_First_mE23AC28EC9ADCDD2688247217CF40C800E780B97_ComCallableWrapperProjectedMethod(GetManagedObjectInline(), comReturnValue);
	}
};

IL2CPP_EXTERN_C Il2CppIUnknown* CreateComCallableWrapperFor_Dictionary_2_t4EAC15363030DFDF453F1AB77D690425033951F5(RuntimeObject* obj)
{
	void* memory = il2cpp::utils::Memory::Malloc(sizeof(Dictionary_2_t4EAC15363030DFDF453F1AB77D690425033951F5_ComCallableWrapper));
	if (memory == NULL)
	{
		il2cpp_codegen_raise_out_of_memory_exception();
	}

	return static_cast<Il2CppIManagedObjectHolder*>(new(memory) Dictionary_2_t4EAC15363030DFDF453F1AB77D690425033951F5_ComCallableWrapper(obj));
}

struct Dictionary_2_tBE995FA87CE27220FD97BCC009668BA7930F425B_ComCallableWrapper IL2CPP_FINAL : il2cpp::vm::CachedCCWBase<Dictionary_2_tBE995FA87CE27220FD97BCC009668BA7930F425B_ComCallableWrapper>, IBindableIterable_t257967EF5CDA5DFD63615802571892212B01796C
{
	inline Dictionary_2_tBE995FA87CE27220FD97BCC009668BA7930F425B_ComCallableWrapper(RuntimeObject* obj) : il2cpp::vm::CachedCCWBase<Dictionary_2_tBE995FA87CE27220FD97BCC009668BA7930F425B_ComCallableWrapper>(obj) {}

	virtual il2cpp_hresult_t STDCALL QueryInterface(const Il2CppGuid& iid, void** object) IL2CPP_OVERRIDE
	{
		if (::memcmp(&iid, &Il2CppIUnknown::IID, sizeof(Il2CppGuid)) == 0
		 || ::memcmp(&iid, &Il2CppIInspectable::IID, sizeof(Il2CppGuid)) == 0
		 || ::memcmp(&iid, &Il2CppIAgileObject::IID, sizeof(Il2CppGuid)) == 0)
		{
			*object = GetIdentity();
			AddRefImpl();
			return IL2CPP_S_OK;
		}

		if (::memcmp(&iid, &Il2CppIManagedObjectHolder::IID, sizeof(Il2CppGuid)) == 0)
		{
			*object = static_cast<Il2CppIManagedObjectHolder*>(this);
			AddRefImpl();
			return IL2CPP_S_OK;
		}

		if (::memcmp(&iid, &IBindableIterable_t257967EF5CDA5DFD63615802571892212B01796C::IID, sizeof(Il2CppGuid)) == 0)
		{
			*object = static_cast<IBindableIterable_t257967EF5CDA5DFD63615802571892212B01796C*>(this);
			AddRefImpl();
			return IL2CPP_S_OK;
		}

		if (::memcmp(&iid, &Il2CppIMarshal::IID, sizeof(Il2CppGuid)) == 0)
		{
			*object = static_cast<Il2CppIMarshal*>(this);
			AddRefImpl();
			return IL2CPP_S_OK;
		}

		if (::memcmp(&iid, &Il2CppIWeakReferenceSource::IID, sizeof(Il2CppGuid)) == 0)
		{
			*object = static_cast<Il2CppIWeakReferenceSource*>(this);
			AddRefImpl();
			return IL2CPP_S_OK;
		}

		*object = NULL;
		return IL2CPP_E_NOINTERFACE;
	}

	virtual uint32_t STDCALL AddRef() IL2CPP_OVERRIDE
	{
		return AddRefImpl();
	}

	virtual uint32_t STDCALL Release() IL2CPP_OVERRIDE
	{
		return ReleaseImpl();
	}

	virtual il2cpp_hresult_t STDCALL GetIids(uint32_t* iidCount, Il2CppGuid** iids) IL2CPP_OVERRIDE
	{
		Il2CppGuid* interfaceIds = il2cpp_codegen_marshal_allocate_array<Il2CppGuid>(1);
		interfaceIds[0] = IBindableIterable_t257967EF5CDA5DFD63615802571892212B01796C::IID;

		*iidCount = 1;
		*iids = interfaceIds;
		return IL2CPP_S_OK;
	}

	virtual il2cpp_hresult_t STDCALL GetRuntimeClassName(Il2CppHString* className) IL2CPP_OVERRIDE
	{
		return GetRuntimeClassNameImpl(className);
	}

	virtual il2cpp_hresult_t STDCALL GetTrustLevel(int32_t* trustLevel) IL2CPP_OVERRIDE
	{
		return ComObjectBase::GetTrustLevel(trustLevel);
	}

	virtual il2cpp_hresult_t STDCALL IBindableIterable_First_mE23AC28EC9ADCDD2688247217CF40C800E780B97(IBindableIterator_t63CCD2268CEE8AFAB68518869D47C5BDAF72962F** comReturnValue) IL2CPP_OVERRIDE
	{
		return IBindableIterable_First_mE23AC28EC9ADCDD2688247217CF40C800E780B97_ComCallableWrapperProjectedMethod(GetManagedObjectInline(), comReturnValue);
	}
};

IL2CPP_EXTERN_C Il2CppIUnknown* CreateComCallableWrapperFor_Dictionary_2_tBE995FA87CE27220FD97BCC009668BA7930F425B(RuntimeObject* obj)
{
	void* memory = il2cpp::utils::Memory::Malloc(sizeof(Dictionary_2_tBE995FA87CE27220FD97BCC009668BA7930F425B_ComCallableWrapper));
	if (memory == NULL)
	{
		il2cpp_codegen_raise_out_of_memory_exception();
	}

	return static_cast<Il2CppIManagedObjectHolder*>(new(memory) Dictionary_2_tBE995FA87CE27220FD97BCC009668BA7930F425B_ComCallableWrapper(obj));
}

struct Dictionary_2_tD67DCDAF66E2D5C2520AA4035B35E6DCC259DB41_ComCallableWrapper IL2CPP_FINAL : il2cpp::vm::CachedCCWBase<Dictionary_2_tD67DCDAF66E2D5C2520AA4035B35E6DCC259DB41_ComCallableWrapper>, IBindableIterable_t257967EF5CDA5DFD63615802571892212B01796C
{
	inline Dictionary_2_tD67DCDAF66E2D5C2520AA4035B35E6DCC259DB41_ComCallableWrapper(RuntimeObject* obj) : il2cpp::vm::CachedCCWBase<Dictionary_2_tD67DCDAF66E2D5C2520AA4035B35E6DCC259DB41_ComCallableWrapper>(obj) {}

	virtual il2cpp_hresult_t STDCALL QueryInterface(const Il2CppGuid& iid, void** object) IL2CPP_OVERRIDE
	{
		if (::memcmp(&iid, &Il2CppIUnknown::IID, sizeof(Il2CppGuid)) == 0
		 || ::memcmp(&iid, &Il2CppIInspectable::IID, sizeof(Il2CppGuid)) == 0
		 || ::memcmp(&iid, &Il2CppIAgileObject::IID, sizeof(Il2CppGuid)) == 0)
		{
			*object = GetIdentity();
			AddRefImpl();
			return IL2CPP_S_OK;
		}

		if (::memcmp(&iid, &Il2CppIManagedObjectHolder::IID, sizeof(Il2CppGuid)) == 0)
		{
			*object = static_cast<Il2CppIManagedObjectHolder*>(this);
			AddRefImpl();
			return IL2CPP_S_OK;
		}

		if (::memcmp(&iid, &IBindableIterable_t257967EF5CDA5DFD63615802571892212B01796C::IID, sizeof(Il2CppGuid)) == 0)
		{
			*object = static_cast<IBindableIterable_t257967EF5CDA5DFD63615802571892212B01796C*>(this);
			AddRefImpl();
			return IL2CPP_S_OK;
		}

		if (::memcmp(&iid, &Il2CppIMarshal::IID, sizeof(Il2CppGuid)) == 0)
		{
			*object = static_cast<Il2CppIMarshal*>(this);
			AddRefImpl();
			return IL2CPP_S_OK;
		}

		if (::memcmp(&iid, &Il2CppIWeakReferenceSource::IID, sizeof(Il2CppGuid)) == 0)
		{
			*object = static_cast<Il2CppIWeakReferenceSource*>(this);
			AddRefImpl();
			return IL2CPP_S_OK;
		}

		*object = NULL;
		return IL2CPP_E_NOINTERFACE;
	}

	virtual uint32_t STDCALL AddRef() IL2CPP_OVERRIDE
	{
		return AddRefImpl();
	}

	virtual uint32_t STDCALL Release() IL2CPP_OVERRIDE
	{
		return ReleaseImpl();
	}

	virtual il2cpp_hresult_t STDCALL GetIids(uint32_t* iidCount, Il2CppGuid** iids) IL2CPP_OVERRIDE
	{
		Il2CppGuid* interfaceIds = il2cpp_codegen_marshal_allocate_array<Il2CppGuid>(1);
		interfaceIds[0] = IBindableIterable_t257967EF5CDA5DFD63615802571892212B01796C::IID;

		*iidCount = 1;
		*iids = interfaceIds;
		return IL2CPP_S_OK;
	}

	virtual il2cpp_hresult_t STDCALL GetRuntimeClassName(Il2CppHString* className) IL2CPP_OVERRIDE
	{
		return GetRuntimeClassNameImpl(className);
	}

	virtual il2cpp_hresult_t STDCALL GetTrustLevel(int32_t* trustLevel) IL2CPP_OVERRIDE
	{
		return ComObjectBase::GetTrustLevel(trustLevel);
	}

	virtual il2cpp_hresult_t STDCALL IBindableIterable_First_mE23AC28EC9ADCDD2688247217CF40C800E780B97(IBindableIterator_t63CCD2268CEE8AFAB68518869D47C5BDAF72962F** comReturnValue) IL2CPP_OVERRIDE
	{
		return IBindableIterable_First_mE23AC28EC9ADCDD2688247217CF40C800E780B97_ComCallableWrapperProjectedMethod(GetManagedObjectInline(), comReturnValue);
	}
};

IL2CPP_EXTERN_C Il2CppIUnknown* CreateComCallableWrapperFor_Dictionary_2_tD67DCDAF66E2D5C2520AA4035B35E6DCC259DB41(RuntimeObject* obj)
{
	void* memory = il2cpp::utils::Memory::Malloc(sizeof(Dictionary_2_tD67DCDAF66E2D5C2520AA4035B35E6DCC259DB41_ComCallableWrapper));
	if (memory == NULL)
	{
		il2cpp_codegen_raise_out_of_memory_exception();
	}

	return static_cast<Il2CppIManagedObjectHolder*>(new(memory) Dictionary_2_tD67DCDAF66E2D5C2520AA4035B35E6DCC259DB41_ComCallableWrapper(obj));
}

struct Dictionary_2_tBFA6A92ADF404217ADC6287258F898AC33533339_ComCallableWrapper IL2CPP_FINAL : il2cpp::vm::CachedCCWBase<Dictionary_2_tBFA6A92ADF404217ADC6287258F898AC33533339_ComCallableWrapper>, IBindableIterable_t257967EF5CDA5DFD63615802571892212B01796C
{
	inline Dictionary_2_tBFA6A92ADF404217ADC6287258F898AC33533339_ComCallableWrapper(RuntimeObject* obj) : il2cpp::vm::CachedCCWBase<Dictionary_2_tBFA6A92ADF404217ADC6287258F898AC33533339_ComCallableWrapper>(obj) {}

	virtual il2cpp_hresult_t STDCALL QueryInterface(const Il2CppGuid& iid, void** object) IL2CPP_OVERRIDE
	{
		if (::memcmp(&iid, &Il2CppIUnknown::IID, sizeof(Il2CppGuid)) == 0
		 || ::memcmp(&iid, &Il2CppIInspectable::IID, sizeof(Il2CppGuid)) == 0
		 || ::memcmp(&iid, &Il2CppIAgileObject::IID, sizeof(Il2CppGuid)) == 0)
		{
			*object = GetIdentity();
			AddRefImpl();
			return IL2CPP_S_OK;
		}

		if (::memcmp(&iid, &Il2CppIManagedObjectHolder::IID, sizeof(Il2CppGuid)) == 0)
		{
			*object = static_cast<Il2CppIManagedObjectHolder*>(this);
			AddRefImpl();
			return IL2CPP_S_OK;
		}

		if (::memcmp(&iid, &IBindableIterable_t257967EF5CDA5DFD63615802571892212B01796C::IID, sizeof(Il2CppGuid)) == 0)
		{
			*object = static_cast<IBindableIterable_t257967EF5CDA5DFD63615802571892212B01796C*>(this);
			AddRefImpl();
			return IL2CPP_S_OK;
		}

		if (::memcmp(&iid, &Il2CppIMarshal::IID, sizeof(Il2CppGuid)) == 0)
		{
			*object = static_cast<Il2CppIMarshal*>(this);
			AddRefImpl();
			return IL2CPP_S_OK;
		}

		if (::memcmp(&iid, &Il2CppIWeakReferenceSource::IID, sizeof(Il2CppGuid)) == 0)
		{
			*object = static_cast<Il2CppIWeakReferenceSource*>(this);
			AddRefImpl();
			return IL2CPP_S_OK;
		}

		*object = NULL;
		return IL2CPP_E_NOINTERFACE;
	}

	virtual uint32_t STDCALL AddRef() IL2CPP_OVERRIDE
	{
		return AddRefImpl();
	}

	virtual uint32_t STDCALL Release() IL2CPP_OVERRIDE
	{
		return ReleaseImpl();
	}

	virtual il2cpp_hresult_t STDCALL GetIids(uint32_t* iidCount, Il2CppGuid** iids) IL2CPP_OVERRIDE
	{
		Il2CppGuid* interfaceIds = il2cpp_codegen_marshal_allocate_array<Il2CppGuid>(1);
		interfaceIds[0] = IBindableIterable_t257967EF5CDA5DFD63615802571892212B01796C::IID;

		*iidCount = 1;
		*iids = interfaceIds;
		return IL2CPP_S_OK;
	}

	virtual il2cpp_hresult_t STDCALL GetRuntimeClassName(Il2CppHString* className) IL2CPP_OVERRIDE
	{
		return GetRuntimeClassNameImpl(className);
	}

	virtual il2cpp_hresult_t STDCALL GetTrustLevel(int32_t* trustLevel) IL2CPP_OVERRIDE
	{
		return ComObjectBase::GetTrustLevel(trustLevel);
	}

	virtual il2cpp_hresult_t STDCALL IBindableIterable_First_mE23AC28EC9ADCDD2688247217CF40C800E780B97(IBindableIterator_t63CCD2268CEE8AFAB68518869D47C5BDAF72962F** comReturnValue) IL2CPP_OVERRIDE
	{
		return IBindableIterable_First_mE23AC28EC9ADCDD2688247217CF40C800E780B97_ComCallableWrapperProjectedMethod(GetManagedObjectInline(), comReturnValue);
	}
};

IL2CPP_EXTERN_C Il2CppIUnknown* CreateComCallableWrapperFor_Dictionary_2_tBFA6A92ADF404217ADC6287258F898AC33533339(RuntimeObject* obj)
{
	void* memory = il2cpp::utils::Memory::Malloc(sizeof(Dictionary_2_tBFA6A92ADF404217ADC6287258F898AC33533339_ComCallableWrapper));
	if (memory == NULL)
	{
		il2cpp_codegen_raise_out_of_memory_exception();
	}

	return static_cast<Il2CppIManagedObjectHolder*>(new(memory) Dictionary_2_tBFA6A92ADF404217ADC6287258F898AC33533339_ComCallableWrapper(obj));
}

struct Dictionary_2_tE07DE99BCB5707DE2E531BB2B2D5537571B26B7E_ComCallableWrapper IL2CPP_FINAL : il2cpp::vm::CachedCCWBase<Dictionary_2_tE07DE99BCB5707DE2E531BB2B2D5537571B26B7E_ComCallableWrapper>, IBindableIterable_t257967EF5CDA5DFD63615802571892212B01796C
{
	inline Dictionary_2_tE07DE99BCB5707DE2E531BB2B2D5537571B26B7E_ComCallableWrapper(RuntimeObject* obj) : il2cpp::vm::CachedCCWBase<Dictionary_2_tE07DE99BCB5707DE2E531BB2B2D5537571B26B7E_ComCallableWrapper>(obj) {}

	virtual il2cpp_hresult_t STDCALL QueryInterface(const Il2CppGuid& iid, void** object) IL2CPP_OVERRIDE
	{
		if (::memcmp(&iid, &Il2CppIUnknown::IID, sizeof(Il2CppGuid)) == 0
		 || ::memcmp(&iid, &Il2CppIInspectable::IID, sizeof(Il2CppGuid)) == 0
		 || ::memcmp(&iid, &Il2CppIAgileObject::IID, sizeof(Il2CppGuid)) == 0)
		{
			*object = GetIdentity();
			AddRefImpl();
			return IL2CPP_S_OK;
		}

		if (::memcmp(&iid, &Il2CppIManagedObjectHolder::IID, sizeof(Il2CppGuid)) == 0)
		{
			*object = static_cast<Il2CppIManagedObjectHolder*>(this);
			AddRefImpl();
			return IL2CPP_S_OK;
		}

		if (::memcmp(&iid, &IBindableIterable_t257967EF5CDA5DFD63615802571892212B01796C::IID, sizeof(Il2CppGuid)) == 0)
		{
			*object = static_cast<IBindableIterable_t257967EF5CDA5DFD63615802571892212B01796C*>(this);
			AddRefImpl();
			return IL2CPP_S_OK;
		}

		if (::memcmp(&iid, &Il2CppIMarshal::IID, sizeof(Il2CppGuid)) == 0)
		{
			*object = static_cast<Il2CppIMarshal*>(this);
			AddRefImpl();
			return IL2CPP_S_OK;
		}

		if (::memcmp(&iid, &Il2CppIWeakReferenceSource::IID, sizeof(Il2CppGuid)) == 0)
		{
			*object = static_cast<Il2CppIWeakReferenceSource*>(this);
			AddRefImpl();
			return IL2CPP_S_OK;
		}

		*object = NULL;
		return IL2CPP_E_NOINTERFACE;
	}

	virtual uint32_t STDCALL AddRef() IL2CPP_OVERRIDE
	{
		return AddRefImpl();
	}

	virtual uint32_t STDCALL Release() IL2CPP_OVERRIDE
	{
		return ReleaseImpl();
	}

	virtual il2cpp_hresult_t STDCALL GetIids(uint32_t* iidCount, Il2CppGuid** iids) IL2CPP_OVERRIDE
	{
		Il2CppGuid* interfaceIds = il2cpp_codegen_marshal_allocate_array<Il2CppGuid>(1);
		interfaceIds[0] = IBindableIterable_t257967EF5CDA5DFD63615802571892212B01796C::IID;

		*iidCount = 1;
		*iids = interfaceIds;
		return IL2CPP_S_OK;
	}

	virtual il2cpp_hresult_t STDCALL GetRuntimeClassName(Il2CppHString* className) IL2CPP_OVERRIDE
	{
		return GetRuntimeClassNameImpl(className);
	}

	virtual il2cpp_hresult_t STDCALL GetTrustLevel(int32_t* trustLevel) IL2CPP_OVERRIDE
	{
		return ComObjectBase::GetTrustLevel(trustLevel);
	}

	virtual il2cpp_hresult_t STDCALL IBindableIterable_First_mE23AC28EC9ADCDD2688247217CF40C800E780B97(IBindableIterator_t63CCD2268CEE8AFAB68518869D47C5BDAF72962F** comReturnValue) IL2CPP_OVERRIDE
	{
		return IBindableIterable_First_mE23AC28EC9ADCDD2688247217CF40C800E780B97_ComCallableWrapperProjectedMethod(GetManagedObjectInline(), comReturnValue);
	}
};

IL2CPP_EXTERN_C Il2CppIUnknown* CreateComCallableWrapperFor_Dictionary_2_tE07DE99BCB5707DE2E531BB2B2D5537571B26B7E(RuntimeObject* obj)
{
	void* memory = il2cpp::utils::Memory::Malloc(sizeof(Dictionary_2_tE07DE99BCB5707DE2E531BB2B2D5537571B26B7E_ComCallableWrapper));
	if (memory == NULL)
	{
		il2cpp_codegen_raise_out_of_memory_exception();
	}

	return static_cast<Il2CppIManagedObjectHolder*>(new(memory) Dictionary_2_tE07DE99BCB5707DE2E531BB2B2D5537571B26B7E_ComCallableWrapper(obj));
}

struct Dictionary_2_tD5545BC5C76F0FE1D42E73713A5484EE3FC0A159_ComCallableWrapper IL2CPP_FINAL : il2cpp::vm::CachedCCWBase<Dictionary_2_tD5545BC5C76F0FE1D42E73713A5484EE3FC0A159_ComCallableWrapper>, IBindableIterable_t257967EF5CDA5DFD63615802571892212B01796C
{
	inline Dictionary_2_tD5545BC5C76F0FE1D42E73713A5484EE3FC0A159_ComCallableWrapper(RuntimeObject* obj) : il2cpp::vm::CachedCCWBase<Dictionary_2_tD5545BC5C76F0FE1D42E73713A5484EE3FC0A159_ComCallableWrapper>(obj) {}

	virtual il2cpp_hresult_t STDCALL QueryInterface(const Il2CppGuid& iid, void** object) IL2CPP_OVERRIDE
	{
		if (::memcmp(&iid, &Il2CppIUnknown::IID, sizeof(Il2CppGuid)) == 0
		 || ::memcmp(&iid, &Il2CppIInspectable::IID, sizeof(Il2CppGuid)) == 0
		 || ::memcmp(&iid, &Il2CppIAgileObject::IID, sizeof(Il2CppGuid)) == 0)
		{
			*object = GetIdentity();
			AddRefImpl();
			return IL2CPP_S_OK;
		}

		if (::memcmp(&iid, &Il2CppIManagedObjectHolder::IID, sizeof(Il2CppGuid)) == 0)
		{
			*object = static_cast<Il2CppIManagedObjectHolder*>(this);
			AddRefImpl();
			return IL2CPP_S_OK;
		}

		if (::memcmp(&iid, &IBindableIterable_t257967EF5CDA5DFD63615802571892212B01796C::IID, sizeof(Il2CppGuid)) == 0)
		{
			*object = static_cast<IBindableIterable_t257967EF5CDA5DFD63615802571892212B01796C*>(this);
			AddRefImpl();
			return IL2CPP_S_OK;
		}

		if (::memcmp(&iid, &Il2CppIMarshal::IID, sizeof(Il2CppGuid)) == 0)
		{
			*object = static_cast<Il2CppIMarshal*>(this);
			AddRefImpl();
			return IL2CPP_S_OK;
		}

		if (::memcmp(&iid, &Il2CppIWeakReferenceSource::IID, sizeof(Il2CppGuid)) == 0)
		{
			*object = static_cast<Il2CppIWeakReferenceSource*>(this);
			AddRefImpl();
			return IL2CPP_S_OK;
		}

		*object = NULL;
		return IL2CPP_E_NOINTERFACE;
	}

	virtual uint32_t STDCALL AddRef() IL2CPP_OVERRIDE
	{
		return AddRefImpl();
	}

	virtual uint32_t STDCALL Release() IL2CPP_OVERRIDE
	{
		return ReleaseImpl();
	}

	virtual il2cpp_hresult_t STDCALL GetIids(uint32_t* iidCount, Il2CppGuid** iids) IL2CPP_OVERRIDE
	{
		Il2CppGuid* interfaceIds = il2cpp_codegen_marshal_allocate_array<Il2CppGuid>(1);
		interfaceIds[0] = IBindableIterable_t257967EF5CDA5DFD63615802571892212B01796C::IID;

		*iidCount = 1;
		*iids = interfaceIds;
		return IL2CPP_S_OK;
	}

	virtual il2cpp_hresult_t STDCALL GetRuntimeClassName(Il2CppHString* className) IL2CPP_OVERRIDE
	{
		return GetRuntimeClassNameImpl(className);
	}

	virtual il2cpp_hresult_t STDCALL GetTrustLevel(int32_t* trustLevel) IL2CPP_OVERRIDE
	{
		return ComObjectBase::GetTrustLevel(trustLevel);
	}

	virtual il2cpp_hresult_t STDCALL IBindableIterable_First_mE23AC28EC9ADCDD2688247217CF40C800E780B97(IBindableIterator_t63CCD2268CEE8AFAB68518869D47C5BDAF72962F** comReturnValue) IL2CPP_OVERRIDE
	{
		return IBindableIterable_First_mE23AC28EC9ADCDD2688247217CF40C800E780B97_ComCallableWrapperProjectedMethod(GetManagedObjectInline(), comReturnValue);
	}
};

IL2CPP_EXTERN_C Il2CppIUnknown* CreateComCallableWrapperFor_Dictionary_2_tD5545BC5C76F0FE1D42E73713A5484EE3FC0A159(RuntimeObject* obj)
{
	void* memory = il2cpp::utils::Memory::Malloc(sizeof(Dictionary_2_tD5545BC5C76F0FE1D42E73713A5484EE3FC0A159_ComCallableWrapper));
	if (memory == NULL)
	{
		il2cpp_codegen_raise_out_of_memory_exception();
	}

	return static_cast<Il2CppIManagedObjectHolder*>(new(memory) Dictionary_2_tD5545BC5C76F0FE1D42E73713A5484EE3FC0A159_ComCallableWrapper(obj));
}

struct Dictionary_2_t01224C8DBCCFE276E97D2BF52F4D7B10D3642682_ComCallableWrapper IL2CPP_FINAL : il2cpp::vm::CachedCCWBase<Dictionary_2_t01224C8DBCCFE276E97D2BF52F4D7B10D3642682_ComCallableWrapper>, IMap_2_t873A5BC95B85361B068A4BCF2679E8C7F8891AD1, IIterable_1_tC77B5EDDE910309A730C993BC41B3E9EEBF99F53, IBindableIterable_t257967EF5CDA5DFD63615802571892212B01796C, IMapView_2_t039A6D425D93544903087E0132BAA7C4C4AA8B1E
{
	inline Dictionary_2_t01224C8DBCCFE276E97D2BF52F4D7B10D3642682_ComCallableWrapper(RuntimeObject* obj) : il2cpp::vm::CachedCCWBase<Dictionary_2_t01224C8DBCCFE276E97D2BF52F4D7B10D3642682_ComCallableWrapper>(obj) {}

	virtual il2cpp_hresult_t STDCALL QueryInterface(const Il2CppGuid& iid, void** object) IL2CPP_OVERRIDE
	{
		if (::memcmp(&iid, &Il2CppIUnknown::IID, sizeof(Il2CppGuid)) == 0
		 || ::memcmp(&iid, &Il2CppIInspectable::IID, sizeof(Il2CppGuid)) == 0
		 || ::memcmp(&iid, &Il2CppIAgileObject::IID, sizeof(Il2CppGuid)) == 0)
		{
			*object = GetIdentity();
			AddRefImpl();
			return IL2CPP_S_OK;
		}

		if (::memcmp(&iid, &Il2CppIManagedObjectHolder::IID, sizeof(Il2CppGuid)) == 0)
		{
			*object = static_cast<Il2CppIManagedObjectHolder*>(this);
			AddRefImpl();
			return IL2CPP_S_OK;
		}

		if (::memcmp(&iid, &IMap_2_t873A5BC95B85361B068A4BCF2679E8C7F8891AD1::IID, sizeof(Il2CppGuid)) == 0)
		{
			*object = static_cast<IMap_2_t873A5BC95B85361B068A4BCF2679E8C7F8891AD1*>(this);
			AddRefImpl();
			return IL2CPP_S_OK;
		}

		if (::memcmp(&iid, &IIterable_1_tC77B5EDDE910309A730C993BC41B3E9EEBF99F53::IID, sizeof(Il2CppGuid)) == 0)
		{
			*object = static_cast<IIterable_1_tC77B5EDDE910309A730C993BC41B3E9EEBF99F53*>(this);
			AddRefImpl();
			return IL2CPP_S_OK;
		}

		if (::memcmp(&iid, &IBindableIterable_t257967EF5CDA5DFD63615802571892212B01796C::IID, sizeof(Il2CppGuid)) == 0)
		{
			*object = static_cast<IBindableIterable_t257967EF5CDA5DFD63615802571892212B01796C*>(this);
			AddRefImpl();
			return IL2CPP_S_OK;
		}

		if (::memcmp(&iid, &IMapView_2_t039A6D425D93544903087E0132BAA7C4C4AA8B1E::IID, sizeof(Il2CppGuid)) == 0)
		{
			*object = static_cast<IMapView_2_t039A6D425D93544903087E0132BAA7C4C4AA8B1E*>(this);
			AddRefImpl();
			return IL2CPP_S_OK;
		}

		if (::memcmp(&iid, &Il2CppIMarshal::IID, sizeof(Il2CppGuid)) == 0)
		{
			*object = static_cast<Il2CppIMarshal*>(this);
			AddRefImpl();
			return IL2CPP_S_OK;
		}

		if (::memcmp(&iid, &Il2CppIWeakReferenceSource::IID, sizeof(Il2CppGuid)) == 0)
		{
			*object = static_cast<Il2CppIWeakReferenceSource*>(this);
			AddRefImpl();
			return IL2CPP_S_OK;
		}

		*object = NULL;
		return IL2CPP_E_NOINTERFACE;
	}

	virtual uint32_t STDCALL AddRef() IL2CPP_OVERRIDE
	{
		return AddRefImpl();
	}

	virtual uint32_t STDCALL Release() IL2CPP_OVERRIDE
	{
		return ReleaseImpl();
	}

	virtual il2cpp_hresult_t STDCALL GetIids(uint32_t* iidCount, Il2CppGuid** iids) IL2CPP_OVERRIDE
	{
		Il2CppGuid* interfaceIds = il2cpp_codegen_marshal_allocate_array<Il2CppGuid>(4);
		interfaceIds[0] = IMap_2_t873A5BC95B85361B068A4BCF2679E8C7F8891AD1::IID;
		interfaceIds[1] = IIterable_1_tC77B5EDDE910309A730C993BC41B3E9EEBF99F53::IID;
		interfaceIds[2] = IBindableIterable_t257967EF5CDA5DFD63615802571892212B01796C::IID;
		interfaceIds[3] = IMapView_2_t039A6D425D93544903087E0132BAA7C4C4AA8B1E::IID;

		*iidCount = 4;
		*iids = interfaceIds;
		return IL2CPP_S_OK;
	}

	virtual il2cpp_hresult_t STDCALL GetRuntimeClassName(Il2CppHString* className) IL2CPP_OVERRIDE
	{
		return GetRuntimeClassNameImpl(className);
	}

	virtual il2cpp_hresult_t STDCALL GetTrustLevel(int32_t* trustLevel) IL2CPP_OVERRIDE
	{
		return ComObjectBase::GetTrustLevel(trustLevel);
	}

	virtual il2cpp_hresult_t STDCALL IMap_2_Lookup_m5E7D704F83ECD8DA321C9D5EAB15FD81D0F508F6(int32_t ___0_key, bool* comReturnValue) IL2CPP_OVERRIDE
	{
		return IMap_2_Lookup_m5E7D704F83ECD8DA321C9D5EAB15FD81D0F508F6_ComCallableWrapperProjectedMethod(GetManagedObjectInline(), ___0_key, comReturnValue);
	}

	virtual il2cpp_hresult_t STDCALL IMap_2_get_Size_m3B2434A5F22F58C902D9B0461F2A3AA7819B6D08(uint32_t* comReturnValue) IL2CPP_OVERRIDE
	{
		return IMap_2_get_Size_m3B2434A5F22F58C902D9B0461F2A3AA7819B6D08_ComCallableWrapperProjectedMethod(GetManagedObjectInline(), comReturnValue);
	}

	virtual il2cpp_hresult_t STDCALL IMap_2_HasKey_m60394980063C15911ACEFEC6514862CBBC7A95EA(int32_t ___0_key, bool* comReturnValue) IL2CPP_OVERRIDE
	{
		return IMap_2_HasKey_m60394980063C15911ACEFEC6514862CBBC7A95EA_ComCallableWrapperProjectedMethod(GetManagedObjectInline(), ___0_key, comReturnValue);
	}

	virtual il2cpp_hresult_t STDCALL IMap_2_GetView_m7B7F9E15872477D63031DB0298735A3E4B0C61D8(IMapView_2_t039A6D425D93544903087E0132BAA7C4C4AA8B1E** comReturnValue) IL2CPP_OVERRIDE
	{
		return IMap_2_GetView_m7B7F9E15872477D63031DB0298735A3E4B0C61D8_ComCallableWrapperProjectedMethod(GetManagedObjectInline(), comReturnValue);
	}

	virtual il2cpp_hresult_t STDCALL IMap_2_Insert_mCB092C48F5BA8B47182D2C5BC9F04996C487EC78(int32_t ___0_key, bool ___1_value, bool* comReturnValue) IL2CPP_OVERRIDE
	{
		return IMap_2_Insert_mCB092C48F5BA8B47182D2C5BC9F04996C487EC78_ComCallableWrapperProjectedMethod(GetManagedObjectInline(), ___0_key, ___1_value, comReturnValue);
	}

	virtual il2cpp_hresult_t STDCALL IMap_2_Remove_m7BCAF8AF8B7C3B565CD41332AA256849815F2E71(int32_t ___0_key) IL2CPP_OVERRIDE
	{
		return IMap_2_Remove_m7BCAF8AF8B7C3B565CD41332AA256849815F2E71_ComCallableWrapperProjectedMethod(GetManagedObjectInline(), ___0_key);
	}

	virtual il2cpp_hresult_t STDCALL IMap_2_Clear_mE6DBB1691EBB8FB7283A555622CDDAFBED9232C4() IL2CPP_OVERRIDE
	{
		return IMap_2_Clear_mE6DBB1691EBB8FB7283A555622CDDAFBED9232C4_ComCallableWrapperProjectedMethod(GetManagedObjectInline());
	}

	virtual il2cpp_hresult_t STDCALL IIterable_1_First_mFD302876C9FFDC28D63D8F32AF019F65A059E930(IIterator_1_t88F3ACE96E95F4306BB1B6297F9035FF9344CFCD** comReturnValue) IL2CPP_OVERRIDE
	{
		return IIterable_1_First_mFD302876C9FFDC28D63D8F32AF019F65A059E930_ComCallableWrapperProjectedMethod(GetManagedObjectInline(), comReturnValue);
	}

	virtual il2cpp_hresult_t STDCALL IBindableIterable_First_mE23AC28EC9ADCDD2688247217CF40C800E780B97(IBindableIterator_t63CCD2268CEE8AFAB68518869D47C5BDAF72962F** comReturnValue) IL2CPP_OVERRIDE
	{
		return IBindableIterable_First_mE23AC28EC9ADCDD2688247217CF40C800E780B97_ComCallableWrapperProjectedMethod(GetManagedObjectInline(), comReturnValue);
	}

	virtual il2cpp_hresult_t STDCALL IMapView_2_Lookup_m24D5938C10FB85A7D76DC9B5F859EC1E9ABCF366(int32_t ___0_key, bool* comReturnValue) IL2CPP_OVERRIDE
	{
		return IMapView_2_Lookup_m24D5938C10FB85A7D76DC9B5F859EC1E9ABCF366_ComCallableWrapperProjectedMethod(GetManagedObjectInline(), ___0_key, comReturnValue);
	}

	virtual il2cpp_hresult_t STDCALL IMapView_2_get_Size_mA24B602FF8F1560E6EEB4FE3A8867F97683528F3(uint32_t* comReturnValue) IL2CPP_OVERRIDE
	{
		return IMapView_2_get_Size_mA24B602FF8F1560E6EEB4FE3A8867F97683528F3_ComCallableWrapperProjectedMethod(GetManagedObjectInline(), comReturnValue);
	}

	virtual il2cpp_hresult_t STDCALL IMapView_2_HasKey_m82681036A649B64BA426284FF5EDA26A39C8732F(int32_t ___0_key, bool* comReturnValue) IL2CPP_OVERRIDE
	{
		return IMapView_2_HasKey_m82681036A649B64BA426284FF5EDA26A39C8732F_ComCallableWrapperProjectedMethod(GetManagedObjectInline(), ___0_key, comReturnValue);
	}

	virtual il2cpp_hresult_t STDCALL IMapView_2_Split_m73E25E3D118B7DA54DC9B4E39FCD9021A32E97C7(IMapView_2_t039A6D425D93544903087E0132BAA7C4C4AA8B1E** ___0_first, IMapView_2_t039A6D425D93544903087E0132BAA7C4C4AA8B1E** ___1_second) IL2CPP_OVERRIDE
	{
		return IMapView_2_Split_m73E25E3D118B7DA54DC9B4E39FCD9021A32E97C7_ComCallableWrapperProjectedMethod(GetManagedObjectInline(), ___0_first, ___1_second);
	}
};

IL2CPP_EXTERN_C Il2CppIUnknown* CreateComCallableWrapperFor_Dictionary_2_t01224C8DBCCFE276E97D2BF52F4D7B10D3642682(RuntimeObject* obj)
{
	void* memory = il2cpp::utils::Memory::Malloc(sizeof(Dictionary_2_t01224C8DBCCFE276E97D2BF52F4D7B10D3642682_ComCallableWrapper));
	if (memory == NULL)
	{
		il2cpp_codegen_raise_out_of_memory_exception();
	}

	return static_cast<Il2CppIManagedObjectHolder*>(new(memory) Dictionary_2_t01224C8DBCCFE276E97D2BF52F4D7B10D3642682_ComCallableWrapper(obj));
}
