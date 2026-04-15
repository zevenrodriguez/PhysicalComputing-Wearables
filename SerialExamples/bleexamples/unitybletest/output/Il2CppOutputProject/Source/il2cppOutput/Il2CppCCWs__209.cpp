#include "pch-cpp.hpp"




#include "vm/CachedCCWBase.h"
#include "utils/New.h"


struct CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB;
struct IUriEscapeStatics_t8B2F0E41F1929CFED9EE91D1975AFD4E28F5A72A;
struct IUriRuntimeClassFactory_t35F7F1D9321A3A02A1C72E2430DD9354467F64CE;
struct String_t;
struct Uri_t1500A52B5F71A04F5D05C0852D0F2A0941842A0E;
struct UriParser_t920B0868286118827C08B08A15A9456AF6C19D81;
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915;
struct UriInfo_t5F91F77A93545DDDA6BB24A609BAF5E232CC1A09;

IL2CPP_EXTERN_C RuntimeClass* Uri_tD1E8897214B1074322A9A3ACD9CEEC69C6275D71_il2cpp_TypeInfo_var;
struct IUriRuntimeClass_t77131E3CF0A817225A9D0A86CD079B4BCA0B37AE;
struct IUriRuntimeClass_t77131E3CF0A817225A9D0A86CD079B4BCA0B37AE;;
struct IWwwFormUrlDecoderRuntimeClass_t57587268E168722CF98FC3817DD9B10DAEA20F4B;


IL2CPP_EXTERN_C_BEGIN
IL2CPP_EXTERN_C_END

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
struct NOVTABLE IClosable_t408735E2F18F562F8A87A4C359E73D7C30A1D301 : Il2CppIInspectable
{
	static const Il2CppGuid IID;
	virtual il2cpp_hresult_t STDCALL IClosable_Close_mCB0DF137CDDDCC22063CF8D95ECE3BC9B8FA0D88() = 0;
};
struct NOVTABLE IUriEscapeStatics_t8B2F0E41F1929CFED9EE91D1975AFD4E28F5A72A : Il2CppIInspectable
{
	static const Il2CppGuid IID;
	virtual il2cpp_hresult_t STDCALL IUriEscapeStatics_UnescapeComponent_m1559688DC4B741F4E168046BF4D9A0C06660961F(Il2CppHString ___0_toUnescape, Il2CppHString* comReturnValue) = 0;
	virtual il2cpp_hresult_t STDCALL IUriEscapeStatics_EscapeComponent_m67C61D8DA96A3B8697B5BD82A4CC096CB16B59CC(Il2CppHString ___0_toEscape, Il2CppHString* comReturnValue) = 0;
};
struct NOVTABLE IUriRuntimeClass_t77131E3CF0A817225A9D0A86CD079B4BCA0B37AE : Il2CppIInspectable
{
	static const Il2CppGuid IID;
	virtual il2cpp_hresult_t STDCALL IUriRuntimeClass_get_AbsoluteUri_mFDCD818FFB98928B96C10622CBD1FA51211A5039(Il2CppHString* comReturnValue) = 0;
	virtual il2cpp_hresult_t STDCALL IUriRuntimeClass_get_DisplayUri_mA5BE547BC2431DED6C4D81B0AFBAF8BA4CE75CAE(Il2CppHString* comReturnValue) = 0;
	virtual il2cpp_hresult_t STDCALL IUriRuntimeClass_get_Domain_m9F9286C83E51B7189CB600FDA56536B6C3D3DEF4(Il2CppHString* comReturnValue) = 0;
	virtual il2cpp_hresult_t STDCALL IUriRuntimeClass_get_Extension_m3A68BA69407CF26B34983E7F64773C40EAF53EF7(Il2CppHString* comReturnValue) = 0;
	virtual il2cpp_hresult_t STDCALL IUriRuntimeClass_get_Fragment_mF816CF64BF304B68776A0ACF07FFD0DE4BF923BE(Il2CppHString* comReturnValue) = 0;
	virtual il2cpp_hresult_t STDCALL IUriRuntimeClass_get_Host_mBA35AB060BD248430CE426EC1C79D61BE0478FF1(Il2CppHString* comReturnValue) = 0;
	virtual il2cpp_hresult_t STDCALL IUriRuntimeClass_get_Password_m10F5E5882F41CA9A16EFB5F4176B076619DB526D(Il2CppHString* comReturnValue) = 0;
	virtual il2cpp_hresult_t STDCALL IUriRuntimeClass_get_Path_mF177B908F7DFEA4E1A92659A12CF59C7176820E9(Il2CppHString* comReturnValue) = 0;
	virtual il2cpp_hresult_t STDCALL IUriRuntimeClass_get_Query_m36CCE81848E9E19661035022E0F5E6BF69201DB3(Il2CppHString* comReturnValue) = 0;
	virtual il2cpp_hresult_t STDCALL IUriRuntimeClass_get_QueryParsed_m9CC25D727B6BF3EC0EFCB3584D54E7A6E6A74697(IWwwFormUrlDecoderRuntimeClass_t57587268E168722CF98FC3817DD9B10DAEA20F4B** comReturnValue) = 0;
	virtual il2cpp_hresult_t STDCALL IUriRuntimeClass_get_RawUri_m6E5DB6C3941C5EF53C92F0B5C001B496A81D6530(Il2CppHString* comReturnValue) = 0;
	virtual il2cpp_hresult_t STDCALL IUriRuntimeClass_get_SchemeName_m65F49F0257521ABE08C79C1A477E13B60E65FB40(Il2CppHString* comReturnValue) = 0;
	virtual il2cpp_hresult_t STDCALL IUriRuntimeClass_get_UserName_m0E333766D1063D8D7CD8A3B7CC787BA9FAC7F04F(Il2CppHString* comReturnValue) = 0;
	virtual il2cpp_hresult_t STDCALL IUriRuntimeClass_get_Port_m806BE81A7A6B20A7CD99AB69837F41684C26E61A(int32_t* comReturnValue) = 0;
	virtual il2cpp_hresult_t STDCALL IUriRuntimeClass_get_Suspicious_mFC3CC720F852478C233ADD5F5C2410874298A751(bool* comReturnValue) = 0;
	virtual il2cpp_hresult_t STDCALL IUriRuntimeClass_Equals_mE5E8B8EF7D5F91CD5E48DD92A6E1399198D68597(IUriRuntimeClass_t77131E3CF0A817225A9D0A86CD079B4BCA0B37AE* ___0_pUri, bool* comReturnValue) = 0;
	virtual il2cpp_hresult_t STDCALL IUriRuntimeClass_CombineUri_mF3F98D12A7247BE0899D65528E197B04E8EBE266(Il2CppHString ___0_relativeUri, IUriRuntimeClass_t77131E3CF0A817225A9D0A86CD079B4BCA0B37AE** comReturnValue) = 0;
};
struct NOVTABLE IUriRuntimeClassFactory_t35F7F1D9321A3A02A1C72E2430DD9354467F64CE : Il2CppIInspectable
{
	static const Il2CppGuid IID;
	virtual il2cpp_hresult_t STDCALL IUriRuntimeClassFactory_CreateUri_mCF30329BAE65E0331EC48E2DD19D8CCDDAA2CB1B(Il2CppHString ___0_uri, IUriRuntimeClass_t77131E3CF0A817225A9D0A86CD079B4BCA0B37AE** comReturnValue) = 0;
	virtual il2cpp_hresult_t STDCALL IUriRuntimeClassFactory_CreateWithRelativeUri_m14565D3D2C8C04CAF5E203690E21067A5909E9B6(Il2CppHString ___0_baseUri, Il2CppHString ___1_relativeUri, IUriRuntimeClass_t77131E3CF0A817225A9D0A86CD079B4BCA0B37AE** comReturnValue) = 0;
};
struct Uri_tD1E8897214B1074322A9A3ACD9CEEC69C6275D71  : public Il2CppComObject
{
};
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F  : public RuntimeObject
{
};
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F_marshaled_pinvoke
{
};
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F_marshaled_com
{
};
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2  : public ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F
{
};
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2_marshaled_pinvoke
{
};
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2_marshaled_com
{
};
struct AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 
{
	uint16_t ___Index;
	uint16_t ___Version;
};
struct UntypedUnsafeList_tB7A46F76589C71832F1147292E5123FB99E199B2 
{
	void* ___Ptr;
	int32_t ___m_length;
	int32_t ___m_capacity;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
	int32_t ___padding;
};
struct UriIdnScope_t001CC97A6F977E9BB7DB855CC6BA415A7F47491F 
{
	int32_t ___value__;
};
struct Flags_t47CF4DB4036A6A539AFA6EE39C75F772E865E897 
{
	uint64_t ___value__;
};
struct UnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67 
{
	UntypedUnsafeList_tB7A46F76589C71832F1147292E5123FB99E199B2 ___m_UntypedListData;
};
struct Uri_t1500A52B5F71A04F5D05C0852D0F2A0941842A0E  : public RuntimeObject
{
	String_t* ___m_String;
	String_t* ___m_originalUnicodeString;
	UriParser_t920B0868286118827C08B08A15A9456AF6C19D81* ___m_Syntax;
	String_t* ___m_DnsSafeHost;
	uint64_t ___m_Flags;
	UriInfo_t5F91F77A93545DDDA6BB24A609BAF5E232CC1A09* ___m_Info;
	bool ___m_iriParsing;
};
struct Uri_tD1E8897214B1074322A9A3ACD9CEEC69C6275D71_StaticFields
{
	Il2CppIActivationFactory* activationFactory;
	IUriRuntimeClassFactory_t35F7F1D9321A3A02A1C72E2430DD9354467F64CE* ____iuriRuntimeClassFactory_t35F7F1D9321A3A02A1C72E2430DD9354467F64CE;
	IUriEscapeStatics_t8B2F0E41F1929CFED9EE91D1975AFD4E28F5A72A* ____iuriEscapeStatics_t8B2F0E41F1929CFED9EE91D1975AFD4E28F5A72A;
	inline Il2CppIActivationFactory* get_activationFactory()
	{
		Il2CppIActivationFactory* returnValue = activationFactory;
		if (returnValue == NULL)
		{
			il2cpp::utils::StringView<Il2CppNativeChar> className(IL2CPP_NATIVE_STRING("Windows.Foundation.Uri"));
			returnValue = il2cpp_codegen_windows_runtime_get_activation_factory(className);

			if (il2cpp_codegen_atomic_compare_exchange_pointer((void**)(&activationFactory), returnValue, NULL) != NULL)
			{
				returnValue->Release();
				returnValue = activationFactory;
			}
		}
		return returnValue;
	}

	inline IUriRuntimeClassFactory_t35F7F1D9321A3A02A1C72E2430DD9354467F64CE* get_____iuriRuntimeClassFactory_t35F7F1D9321A3A02A1C72E2430DD9354467F64CE()
	{
		IUriRuntimeClassFactory_t35F7F1D9321A3A02A1C72E2430DD9354467F64CE* returnValue = ____iuriRuntimeClassFactory_t35F7F1D9321A3A02A1C72E2430DD9354467F64CE;
		if (returnValue == NULL)
		{
			const il2cpp_hresult_t hr = get_activationFactory()->QueryInterface(IUriRuntimeClassFactory_t35F7F1D9321A3A02A1C72E2430DD9354467F64CE::IID, reinterpret_cast<void**>(&returnValue));
			il2cpp_codegen_com_raise_exception_if_failed(hr, false);

			if (il2cpp_codegen_atomic_compare_exchange_pointer((void**)(&____iuriRuntimeClassFactory_t35F7F1D9321A3A02A1C72E2430DD9354467F64CE), returnValue, NULL) != NULL)
			{
				returnValue->Release();
				returnValue = ____iuriRuntimeClassFactory_t35F7F1D9321A3A02A1C72E2430DD9354467F64CE;
			}
		}
		return returnValue;
	}

	inline IUriEscapeStatics_t8B2F0E41F1929CFED9EE91D1975AFD4E28F5A72A* get_____iuriEscapeStatics_t8B2F0E41F1929CFED9EE91D1975AFD4E28F5A72A()
	{
		IUriEscapeStatics_t8B2F0E41F1929CFED9EE91D1975AFD4E28F5A72A* returnValue = ____iuriEscapeStatics_t8B2F0E41F1929CFED9EE91D1975AFD4E28F5A72A;
		if (returnValue == NULL)
		{
			const il2cpp_hresult_t hr = get_activationFactory()->QueryInterface(IUriEscapeStatics_t8B2F0E41F1929CFED9EE91D1975AFD4E28F5A72A::IID, reinterpret_cast<void**>(&returnValue));
			il2cpp_codegen_com_raise_exception_if_failed(hr, false);

			if (il2cpp_codegen_atomic_compare_exchange_pointer((void**)(&____iuriEscapeStatics_t8B2F0E41F1929CFED9EE91D1975AFD4E28F5A72A), returnValue, NULL) != NULL)
			{
				returnValue->Release();
				returnValue = ____iuriEscapeStatics_t8B2F0E41F1929CFED9EE91D1975AFD4E28F5A72A;
			}
		}
		return returnValue;
	}
};
struct Uri_t1500A52B5F71A04F5D05C0852D0F2A0941842A0E_StaticFields
{
	String_t* ___UriSchemeFile;
	String_t* ___UriSchemeFtp;
	String_t* ___UriSchemeGopher;
	String_t* ___UriSchemeHttp;
	String_t* ___UriSchemeHttps;
	String_t* ___UriSchemeWs;
	String_t* ___UriSchemeWss;
	String_t* ___UriSchemeMailto;
	String_t* ___UriSchemeNews;
	String_t* ___UriSchemeNntp;
	String_t* ___UriSchemeNetTcp;
	String_t* ___UriSchemeNetPipe;
	String_t* ___SchemeDelimiter;
	bool ___s_ConfigInitialized;
	bool ___s_ConfigInitializing;
	int32_t ___s_IdnScope;
	bool ___s_IriParsing;
	bool ___useDotNetRelativeOrAbsolute;
	bool ___IsWindowsFileSystem;
	RuntimeObject* ___s_initLock;
	CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* ___HexLowerChars;
	CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* ____WSchars;
};
#ifdef __clang__
#pragma clang diagnostic pop
#endif

il2cpp_hresult_t IClosable_Close_mCB0DF137CDDDCC22063CF8D95ECE3BC9B8FA0D88_ComCallableWrapperProjectedMethod(RuntimeObject* __this);


IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Uri_get_OriginalString_m3031F9054CA10F2C55C0E2415CC19810D360A5D6 (Uri_t1500A52B5F71A04F5D05C0852D0F2A0941842A0E* __this, const RuntimeMethod* method) ;

struct UnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67_ComCallableWrapper IL2CPP_FINAL : il2cpp::vm::CachedCCWBase<UnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67_ComCallableWrapper>, IClosable_t408735E2F18F562F8A87A4C359E73D7C30A1D301
{
	inline UnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67_ComCallableWrapper(RuntimeObject* obj) : il2cpp::vm::CachedCCWBase<UnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67_ComCallableWrapper>(obj) {}

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

		if (::memcmp(&iid, &IClosable_t408735E2F18F562F8A87A4C359E73D7C30A1D301::IID, sizeof(Il2CppGuid)) == 0)
		{
			*object = static_cast<IClosable_t408735E2F18F562F8A87A4C359E73D7C30A1D301*>(this);
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
		interfaceIds[0] = IClosable_t408735E2F18F562F8A87A4C359E73D7C30A1D301::IID;

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

	virtual il2cpp_hresult_t STDCALL IClosable_Close_mCB0DF137CDDDCC22063CF8D95ECE3BC9B8FA0D88() IL2CPP_OVERRIDE
	{
		return IClosable_Close_mCB0DF137CDDDCC22063CF8D95ECE3BC9B8FA0D88_ComCallableWrapperProjectedMethod(GetManagedObjectInline());
	}
};

IL2CPP_EXTERN_C Il2CppIUnknown* CreateComCallableWrapperFor_UnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67(RuntimeObject* obj)
{
	void* memory = il2cpp::utils::Memory::Malloc(sizeof(UnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67_ComCallableWrapper));
	if (memory == NULL)
	{
		il2cpp_codegen_raise_out_of_memory_exception();
	}

	return static_cast<Il2CppIManagedObjectHolder*>(new(memory) UnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67_ComCallableWrapper(obj));
}

IL2CPP_EXTERN_C Il2CppIUnknown* CreateComCallableWrapperFor_Uri_t1500A52B5F71A04F5D05C0852D0F2A0941842A0E(RuntimeObject* obj)
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Uri_tD1E8897214B1074322A9A3ACD9CEEC69C6275D71_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	Uri_t1500A52B5F71A04F5D05C0852D0F2A0941842A0E* _this = reinterpret_cast<Uri_t1500A52B5F71A04F5D05C0852D0F2A0941842A0E*>(obj);
	IUriRuntimeClass_t77131E3CF0A817225A9D0A86CD079B4BCA0B37AE* __this_marshaled = NULL;
	if (_this != NULL)
	{
		String_t* _thisAsString;
		_thisAsString = Uri_get_OriginalString_m3031F9054CA10F2C55C0E2415CC19810D360A5D6(_this, NULL);
		Il2CppHString __thisAsString_marshaled = NULL;
		if (_thisAsString == NULL)
		{
			IL2CPP_RAISE_MANAGED_EXCEPTION(il2cpp_codegen_get_argument_null_exception("_thisAsString"), NULL);
		}

		DECLARE_IL2CPP_STRING_AS_STRING_VIEW_OF_NATIVE_CHARS(_thisAsStringNativeView, reinterpret_cast<Il2CppString*>(_thisAsString));
		il2cpp::vm::Il2CppHStringReference _thisAsStringHStringReference(_thisAsStringNativeView);
		__thisAsString_marshaled = _thisAsStringHStringReference;
		il2cpp_hresult_t hr = ((Uri_tD1E8897214B1074322A9A3ACD9CEEC69C6275D71_StaticFields*)Uri_tD1E8897214B1074322A9A3ACD9CEEC69C6275D71_il2cpp_TypeInfo_var->static_fields)->get_____iuriRuntimeClassFactory_t35F7F1D9321A3A02A1C72E2430DD9354467F64CE()->IUriRuntimeClassFactory_CreateUri_mCF30329BAE65E0331EC48E2DD19D8CCDDAA2CB1B(__thisAsString_marshaled, (&__this_marshaled));
		il2cpp_codegen_com_raise_exception_if_failed(hr, false);
	}
	else
	{
		__this_marshaled = NULL;
	}
	return __this_marshaled;
}
