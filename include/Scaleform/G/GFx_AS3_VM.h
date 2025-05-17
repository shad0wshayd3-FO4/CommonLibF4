#pragma once

#include "Scaleform/A/ArrayPaged.h"
#include "Scaleform/G/GFx_AS3_CallFrame.h"
#include "Scaleform/G/GFx_ASString.h"
#include "Scaleform/N/NewOverrideBase.h"

namespace Scaleform::GFx::AS3
{
	class StringManager;

	class __declspec(novtable) VM :
		public NewOverrideBase<329>
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
}
