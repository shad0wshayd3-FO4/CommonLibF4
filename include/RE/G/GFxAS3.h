#pragma once

#include "RE/G/GFxASMovieRootBase.h"
#include "RE/G/GFxASString.h"
#include "RE/S/SFAllocator.h"
#include "RE/S/SFArrayPaged.h"
#include "RE/S/SFMemory.h"

namespace RE::Scaleform
{
	template <class T>
	class AutoPtr
	{
	public:
		// members
		T*   object;  // 00
		bool owner;   // 08
	};
	static_assert(sizeof(AutoPtr<void>) == 0x10);

	class String
	{
	public:
		struct DataDesc
		{
		public:
			// members
			std::uint64_t         size;      // 00
			volatile std::int32_t refCount;  // 08
			char                  data[1];   // 0C
		};
		static_assert(sizeof(DataDesc) == 0x10);

		const char* c_str()
		{
			return (const char*)((heapTypeBits & 0xFFFFFFFFFFFFFFFC) + 12);
		}

		bool empty()
		{
			return (((heapTypeBits & 0xFFFFFFFFFFFFFFFC) & 0x7FFFFFFFFFFFFFFF) == 0);
		}

		// members
		union
		{
			DataDesc*     data;
			std::uint64_t heapTypeBits;
		};  // 00
	};
	static_assert(sizeof(String) == 0x08);

	class StringDataPtr
	{
	public:
		// members
		const char*   str;   // 00
		std::uint64_t size;  // 08
	};
	static_assert(sizeof(StringDataPtr) == 0x10);
}

namespace RE::Scaleform::GFx::AS3
{
	enum class BuiltinType;

	class ASVM;
	class Class;
	class MemoryContextImpl;
	class Object;
	class ThunkInfo;
	class Traits;
	class ValueRegisterFile;
	class VMAbcFile;
	class WeakProxy;

	namespace Abc
	{
		enum class NamespaceKind : std::int32_t
		{
			kUndefined = -1,
			kPublic,
			kProtected,
			kStaticProtected,
			kPrivate,
			kExplicit,
			kPackageInternal
		};

		class MbiInd
		{
		public:
			// members
			std::int32_t ind;  // 00
		};
		static_assert(sizeof(MbiInd) == 0x04);

		class NamespaceInfo
		{
		public:
			// members
			NamespaceKind kind;     // 00
			StringDataPtr NameURI;  // 08
		};
		static_assert(sizeof(NamespaceInfo) == 0x18);

		class ClassTable :
			public NewOverrideBase<338>
		{
		public:
			// members
			std::byte pad[0x18 - 0x00];  // 00
		};
		static_assert(sizeof(ClassTable) == 0x18);

		class ConstPool :
			public NewOverrideBase<339>
		{
		public:
			// members
			std::uint32_t       doubleCount;         // 00
			const std::uint8_t* doubles;             // 08
			std::byte           pad10[0xA0 - 0x10];  // 10
			const NamespaceInfo anyNamespace;        // A0
		};
		static_assert(sizeof(ConstPool) == 0xB8);

		class MethodBodyTable :
			public NewOverrideBase<338>
		{
		public:
			// members
			std::byte pad[0x18];  // 00
		};
		static_assert(sizeof(MethodBodyTable) == 0x18);

		class MethodTable :
			public NewOverrideBase<338>
		{
		public:
			// members
			std::byte pad[0x18];  // 00
		};
		static_assert(sizeof(MethodTable) == 0x18);

		class MetadataTable :
			public NewOverrideBase<338>
		{
		public:
			// members
			std::byte pad[0x18];  // 00
		};
		static_assert(sizeof(MetadataTable) == 0x18);

		class ScriptTable :
			public NewOverrideBase<338>
		{
		public:
			// members
			std::byte pad[0x18];  // 00
		};
		static_assert(sizeof(ScriptTable) == 0x18);

		class TraitTable :
			public NewOverrideBase<338>
		{
		public:
			// members
			std::byte pad[0x18];  // 00
		};
		static_assert(sizeof(TraitTable) == 0x18);

		class __declspec(novtable) alignas(0x10) File :
			public RefCountImpl,  // 00
			public NewOverrideBase<338>
		{
		public:
			virtual ~File();  // 00

			// members
			std::uint32_t     dataSize;      // 010
			Scaleform::String source;        // 018
			std::uint16_t     minorVersion;  // 020
			std::uint16_t     majorVersion;  // 022
			ConstPool         constPool;     // 028
			MethodTable       methods;       // 0E0
			MetadataTable     metadata;      // 0F8
			TraitTable        traits;        // 110
			ClassTable        classes;       // 128
			ScriptTable       scripts;       // 140
			MethodBodyTable   methodBodies;  // 158
		};
		static_assert(sizeof(File) == 0x170);
	}

	namespace ClassTraits
	{
		class Traits;
	}

	namespace Instances
	{
		class Function;
		class ThunkFunction;
	}

	namespace InstanceTraits
	{
		class Traits;
	}

	template <std::int32_t STAT>
	class __declspec(novtable) RefCountBaseGC :
		public NewOverrideBase<STAT>  // 00
	{
	public:
		virtual ~RefCountBaseGC();  // 00

		// members
		union
		{
			void*         rcc;
			std::uint64_t rccRaw;
		};  // 08
		union
		{
			const RefCountBaseGC<STAT>* next;
			const RefCountBaseGC<STAT>* nextRoot;
		};  // 10
		union
		{
			const RefCountBaseGC<STAT>* prev;
			const RefCountBaseGC<STAT>* prevRoot;
		};  // 18
		std::uint32_t refCount;  // 20
	};
	static_assert(sizeof(RefCountBaseGC<328>) == 0x28);

	class __declspec(novtable) GASRefCountBase :
		public RefCountBaseGC<328>  // 00
	{
	public:
	};
	static_assert(sizeof(GASRefCountBase) == 0x28);

	template <typename T>
	class SPtr
	{
	public:
		// members
		T* object;  // 00
	};
	static_assert(sizeof(SPtr<void>) == 0x08);

	class Value
	{
	public:
		struct Extra
		{
		public:
			// members
			WeakProxy* weakProxy;  // 00
		};
		static_assert(sizeof(Extra) == 0x08);

		union V1U
		{
			bool                      vbool;
			std::int32_t              vint;
			std::uint32_t             vuint;
			ASStringNode*             vstr;
			Object*                   vobj;
			Class*                    vclass;
			Instances::Function*      vfunct;
			const ThunkInfo*          vthunk;
			Instances::ThunkFunction* vthunkfunct;
			InstanceTraits::Traits*   instanceTraits;
			ClassTraits::Traits*      classTraits;
		};

		union V2U
		{
			Object*       vobj;
			const Traits* traits;
		};

		struct VStruct
		{
		public:
			// members
			V1U _1;  // 00
			V2U _2;  // 08
		};
		static_assert(sizeof(VStruct) == 0x10);

		union VU
		{
			long double number;
			VStruct     VS;
		};

		// members
		std::uint32_t flags;  // 00
		Extra         bonus;  // 08
		VU            value;  // 10
	};
	static_assert(sizeof(Value) == 0x20);

	class __declspec(novtable) CallFrame :
		public Scaleform::NewOverrideBase<330>
	{
	public:
		// members
		bool                 discardResult;        // 00
		bool                 aCopy;                // 01
		std::uint64_t        scopeStackBaseInd;    // 08
		const std::uint64_t* cp;                   // 10
		ValueRegisterFile*   registerValue;        // 18
		MemoryHeap*          heap;                 // 20
		VMAbcFile*           file;                 // 28
		Abc::MbiInd          MBIIndex;             // 30
		const void*          savedScope;           // 38 - TODO
		const Traits*        originationTraits;    // 40
		void*                scopeStack;           // 48 - TODO
		Value*               prevInitialStackPos;  // 50
		void*                defXMLNamespace;      // 58 - TODO
		Value*               prevFirstStackPos;    // 60
		Value                Invoker;              // 68
	};
	static_assert(sizeof(CallFrame) == 0x88);

	class __declspec(novtable) FlashUI
	{
	public:
		enum class OutputMessageType : std::int32_t
		{
			kMessage,
			kError,
			kWarning,
			kAction
		};

		enum class StateType : std::int32_t
		{
			kError,
			kBreakpoint,
			kPreStep,
			kStep
		};

		virtual ~FlashUI();  // 00

		// add
		virtual void Output(OutputMessageType a_type, const char* a_msg) = 0;  // 01
		virtual bool OnOpCode(std::uint64_t a_opCode) = 0;                     // 02

		// members
		StateType state;        // 08
		bool      needToCheck;  // 0C
	};
	static_assert(sizeof(FlashUI) == 0x10);

	class __declspec(novtable) MovieRoot :
		public Scaleform::GFx::ASMovieRootBase,          // 00
		public Scaleform::GFx::AS3::FlashUI,             // 28
		public Scaleform::GFx::KeyboardState::IListener  // 38
	{
	public:
		class MemContextPtr :
			Ptr<MemoryContextImpl>
		{
		public:
		};
		static_assert(sizeof(MemContextPtr) == 0x08);

		// members
		MemContextPtr memContext;            // 040
		AutoPtr<ASVM> asVM;                  // 048
		std::byte     pad058[0x4A8 - 0x58];  // 058 - TODO
	};
	static_assert(sizeof(MovieRoot) == 0x4A8);

	class StringManager :
		public ASStringBuiltinManagerT<BuiltinType, 65>
	{
	public:
	};
	static_assert(sizeof(StringManager) == 0x218);

	class TypeInfo
	{
	public:
		// members
		std::uint32_t    flags;              // 00
		std::uint16_t    instanceSize;       // 04
		std::uint16_t    classMethodNum;     // 06
		std::uint16_t    classMemberNum;     // 08
		std::uint16_t    instanceMethodNum;  // 0A
		std::uint16_t    instanceMemberNum;  // 0C
		const char*      name;               // 10
		const char*      packageName;        // 18
		const TypeInfo*  parent;             // 20
		const TypeInfo** implements;         // 28
	};
	static_assert(sizeof(TypeInfo) == 0x30);

	class __declspec(novtable) VM :
		public Scaleform::NewOverrideBase<329>
	{
	public:
		enum ErrorID
		{
			eOutOfMemoryError = 0x3E8,
			eNotImplementedError = 0x3E9,
			eInvalidPrecisionError = 0x3EA,
			eInvalidRadixError = 0x3EB,
			eInvokeOnIncompatibleObjectError = 0x3EC,
			eArrayIndexNotIntegerError = 0x3ED,
			eCallOfNonFunctionError = 0x3EE,
			eConstructOfNonFunctionError = 0x3EF,
			eAmbiguousBindingError = 0x3F0,
			eConvertNullToObjectError = 0x3F1,
			eConvertUndefinedToObjectError = 0x3F2,
			eIllegalOpcodeError = 0x3F3,
			eLastInstExceedsCodeSizeError = 0x3F4,
			eFindVarWithNoScopeError = 0x3F5,
			eClassNotFoundError = 0x3F6,
			eIllegalSetDxns = 0x3F7,
			eDescendentsError = 0x3F8,
			eScopeStackOverflowError = 0x3F9,
			eScopeStackUnderflowError = 0x3FA,
			eGetScopeObjectBoundsError = 0x3FB,
			eCannotFallOffMethodError = 0x3FC,
			eInvalidBranchTargetError = 0x3FD,
			eIllegalVoidError = 0x3FE,
			eStackOverflowError = 0x3FF,
			eStackUnderflowError = 0x400,
			eInvalidRegisterError = 0x401,
			eSlotExceedsCountError = 0x402,
			eMethodInfoExceedsCountError = 0x403,
			eDispIdExceedsCountError = 0x404,
			eDispIdUndefinedError = 0x405,
			eStackDepthUnbalancedError = 0x406,
			eScopeDepthUnbalancedError = 0x407,
			eCpoolIndexRangeError = 0x408,
			eCpoolEntryWrongTypeError = 0x409,
			eCheckTypeFailedError = 0x40A,
			eIllegalSuperCallError = 0x40B,
			eCannotAssignToMethodError = 0x40D,
			eRedefinedError = 0x40E,
			eCannotVerifyUntilReferencedError = 0x40F,
			eCantUseInstanceofOnNonObjectError = 0x410,
			eIsTypeMustBeClassError = 0x411,
			eInvalidMagicError = 0x412,
			eInvalidCodeLengthError = 0x413,
			eInvalidMethodInfoFlagsError = 0x414,
			eUnsupportedTraitsKindError = 0x415,
			eMethodInfoOrderError = 0x416,
			eMissingEntryPointError = 0x417,
			ePrototypeTypeError = 0x419,
			eConvertToPrimitiveError = 0x41A,
			eIllegalEarlyBindingError = 0x41B,
			eInvalidURIError = 0x41C,
			eIllegalOverrideError = 0x41D,
			eIllegalExceptionHandlerError = 0x41E,
			eWriteSealedError = 0x420,
			eIllegalSlotError = 0x421,
			eIllegalOperandTypeError = 0x422,
			eClassInfoOrderError = 0x423,
			eClassInfoExceedsCountError = 0x424,
			eNumberOutOfRangeError = 0x425,
			eWrongArgumentCountError = 0x427,
			eCannotCallMethodAsConstructor = 0x428,
			eUndefinedVarError = 0x429,
			eFunctionConstructorError = 0x42A,
			eIllegalNativeMethodBodyError = 0x42B,
			eCannotMergeTypesError = 0x42C,
			eReadSealedError = 0x42D,
			ePropertyNotFoundError = 0x42D,
			eCallNotFoundError = 0x42E,
			eAlreadyBoundError = 0x42F,
			eZeroDispIdError = 0x430,
			eDuplicateDispIdError = 0x431,
			eConstWriteError = 0x432,
			eMathNotFunctionError = 0x433,
			eMathNotConstructorError = 0x434,
			eWriteOnlyError = 0x435,
			eIllegalOpMultinameError = 0x436,
			eIllegalNativeMethodError = 0x437,
			eIllegalNamespaceError = 0x438,
			eReadSealedErrorNs = 0x439,
			eNoDefaultNamespaceError = 0x43A,
			eXMLPrefixNotBound = 0x43B,
			eXMLBadQName = 0x43C,
			eXMLUnterminatedElementTag = 0x43D,
			eXMLOnlyWorksWithOneItemLists = 0x43E,
			eXMLAssignmentToIndexedXMLNotAllowed = 0x43F,
			eXMLMarkupMustBeWellFormed = 0x440,
			eXMLAssigmentOneItemLists = 0x441,
			eXMLMalformedElement = 0x442,
			eXMLUnterminatedCData = 0x443,
			eXMLUnterminatedXMLDecl = 0x444,
			eXMLUnterminatedDocTypeDecl = 0x445,
			eXMLUnterminatedComment = 0x446,
			eXMLUnterminatedAttribute = 0x447,
			eXMLUnterminatedElement = 0x448,
			eXMLUnterminatedProcessingInstruction = 0x449,
			eXMLNamespaceWithPrefixAndNoURI = 0x44A,
			eRegExpFlagsArgumentError = 0x44C,
			eNoScopeError = 0x44D,
			eIllegalDefaultValue = 0x44E,
			eCannotExtendFinalClass = 0x44F,
			eXMLDuplicateAttribute = 0x450,
			eCorruptABCError = 0x453,
			eInvalidBaseClassError = 0x454,
			eDanglingFunctionError = 0x455,
			eCannotExtendError = 0x456,
			eCannotImplementError = 0x457,
			eCoerceArgumentCountError = 0x458,
			eInvalidNewActivationError = 0x459,
			eNoGlobalScopeError = 0x45A,
			eNotConstructorError = 0x45B,
			eApplyError = 0x45C,
			eXMLInvalidName = 0x45D,
			eXMLIllegalCyclicalLoop = 0x45E,
			eDeleteTypeError = 0x45F,
			eDeleteSealedError = 0x460,
			eDuplicateMethodBodyError = 0x461,
			eIllegalInterfaceMethodBodyError = 0x462,
			eFilterError = 0x463,
			eInvalidHasNextError = 0x464,
			eOutOfRangeError = 0x465,
			eVectorFixedError = 0x466,
			eTypeAppOfNonParamType = 0x467,
			eWrongTypeArgCountError = 0x468,
			eFileOpenError = 0x5DC,
			eFileWriteError = 0x5DD,
			eScriptTimeoutError = 0x5DE,
			eScriptTerminatedError = 0x5DF,
			eEndOfFileError = 0x5E0,
			eStringIndexOutOfBoundsError = 0x5E1,
			eInvalidRangeError = 0x5E2,
			eNullArgumentError = 0x5E3,
			eInvalidArgumentError = 0x5E4,
			eShellCompressedDataError = 0x5E5,
			eArrayFilterNonNullObjectError = 0x5E6,
			eParamRangeError = 0x7D6,
			eNullPointerError = 0x7D7,
			eInvalidEnumError = 0x7D8,
			eArgumentError = 0x7DF,
			eAddObjectItselfError = 0x7E8,
			eMustBeChildError = 0x7E9,
			eMustBeNonNegative = 0x7EB,
			eEOFError = 0x7EE,
			eCompressedDataError = 0x80A,
			eIllegalOperationError = 0x81D,
			eProxyGetPropertyError = 0x828,
			eProxySetPropertyError = 0x829,
			eProxyCallPropertyError = 0x82A,
			eProxyHasPropertyError = 0x82B,
			eProxyDeletePropertyError = 0x82C,
			eProxyGetDescendantsError = 0x82D,
			eProxyNextNameIndexError = 0x839,
			eProxyNextNameError = 0x83A,
			eProxyNextValueError = 0x83B,
			eSceneNotFound = 0x83C,
			eFrameLabelNotFoundInScene = 0x83D,
			eSWFHasInvalidData = 0x858,
		};

		class Error
		{
		public:
			// members
			ErrorID  id;       // 04
			ASString message;  // 08
		};
		static_assert(sizeof(Error) == 0x10);

		virtual ~VM();

		CallFrame* GetCurrCallFrame()
		{
			if (callStack.size > 0) {
				auto idx = callStack.size - 1;
				return &callStack.pages[idx >> 6][idx & 0x3F];
			}

			return nullptr;
		}

		// members
		bool                                initialized;            // 008
		bool                                inDestructor;           // 009
		bool                                loadingAbcFile;         // 00A
		StringManager*                      stringManagerRef;       // 010
		std::byte                           pad008[0xE8 - 0x18];    // 018 - TODO
		ArrayPagedCC<CallFrame, 6, 64, 329> callStack;              // 0E8
		std::byte                           pad198[0x2D0 - 0x198];  // 198 - TODO
	};
	static_assert(sizeof(VM) == 0x2D0);

	class __declspec(novtable) ASVM :
		public VM  // 00
	{
	public:
		// members
		std::byte pad2D0[0x3C8 - 0x2D0];  // 2D0
	};
	static_assert(sizeof(ASVM) == 0x3C8);

	class __declspec(novtable) VMFile :
		public GASRefCountBase
	{
	public:
		// members
		VM*       vmRef;               // 28
		std::byte pad30[0x98 - 0x30];  // 30
	};
	static_assert(sizeof(VMFile) == 0x98);

	class __declspec(novtable) VMAbcFile :
		public VMFile
	{
	public:
		// members
		Ptr<Abc::File> file;                // 98
		std::byte      padA0[0xE8 - 0xA0];  // A0
	};
	static_assert(sizeof(VMAbcFile) == 0xE8);
}
