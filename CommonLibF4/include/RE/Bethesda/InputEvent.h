#pragma once

#include "RE/Bethesda/BSFixedString.h"
#include "RE/Bethesda/InputDevice.h"

namespace RE
{
	enum class DIRECTION_VAL : std::int32_t
	{
		kNone = 0x0,
		kUp = 0x1,
		kRight = 0x2,
		kDown = 0x3,
		kLeft = 0x4
	};

	enum class INPUT_EVENT_TYPE : std::int32_t
	{
		kButton = 0x0,
		kMouseMove = 0x1,
		kCursorMove = 0x2,
		kChar = 0x3,
		kThumbstick = 0x4,
		kDeviceConnect = 0x5,
		kKinect = 0x6,
		kNone = 0x7
	};

	enum class BS_BUTTON_CODE : std::int32_t
	{
		kBackspace = 0x08,
		kTab = 0x09,
		kEnter = 0x0D,
		kPause = 0x13,
		kCapsLock = 0x14,
		kEscape = 0x1B,
		kSpace = 0x20,
		kPageUp = 0x21,
		kPageDown = 0x22,
		kEnd = 0x23,
		kHome = 0x24,
		kLeft = 0x25,
		kUp = 0x26,
		kRight = 0x27,
		kDown = 0x28,
		kPrintScreen = 0x2C,
		kInsert = 0x2D,
		kDelete = 0x2E,
		k0 = 0x30,
		k1 = 0x31,
		k2 = 0x32,
		k3 = 0x33,
		k4 = 0x34,
		k5 = 0x35,
		k6 = 0x36,
		k7 = 0x37,
		k8 = 0x38,
		k9 = 0x39,
		kA = 0x41,
		kB = 0x42,
		kC = 0x43,
		kD = 0x44,
		kE = 0x45,
		kF = 0x46,
		kG = 0x47,
		kH = 0x48,
		kI = 0x49,
		kJ = 0x4A,
		kK = 0x4B,
		kL = 0x4C,
		kM = 0x4D,
		kN = 0x4E,
		kO = 0x4F,
		kP = 0x50,
		kQ = 0x51,
		kR = 0x52,
		kS = 0x53,
		kT = 0x54,
		kU = 0x55,
		kV = 0x56,
		kW = 0x57,
		kX = 0x58,
		kY = 0x59,
		kZ = 0x5A,
		kApps = 0x5D,
		kNumpad_0 = 0x60,
		kNumpad_1 = 0x61,
		kNumpad_2 = 0x62,
		kNumpad_3 = 0x63,
		kNumpad_4 = 0x64,
		kNumpad_5 = 0x65,
		kNumpad_6 = 0x66,
		kNumpad_7 = 0x67,
		kNumpad_8 = 0x68,
		kNumpad_9 = 0x69,
		kNumpad_Multiply = 0x6A,
		kNumpad_Plus = 0x6B,
		kNumpad_Minus = 0x6D,
		kNumpad_Period = 0x6E,
		kNumpad_Divide = 0x6F,
		kF1 = 0x70,
		kF2 = 0x71,
		kF3 = 0x72,
		kF4 = 0x73,
		kF5 = 0x74,
		kF6 = 0x75,
		kF7 = 0x76,
		kF8 = 0x77,
		kF9 = 0x78,
		kF10 = 0x79,
		kF11 = 0x7A,
		kF12 = 0x7B,
		kSemicolon = 0xBA,
		kComma = 0xBC,
		kEquals = 0xBB,
		kMinus = 0xBD,
		kPeriod = 0xBE,
		kDivide = 0xBF,
		kLBracket = 0xDB,
		kBackslash = 0xDC,
		kRBracket = 0xDD,
		kApostrophe = 0xDE,
		kLShift = 0xA0,
		kRShift = 0xA1,
		kLControl = 0xA2,
		kRControl = 0xA3,
		kLAlt = 0xA4,
		kRAlt = 0xA5,
		kNumLock = 0x90,
		kScrollLock = 0x91,

		kGamepad = 0x10000,
		kDPAD_Up = 0x10001,
		kDPAD_Down = 0x10002,
		kDPAD_Left = 0x10004,
		kDPAD_Right = 0x10008,
		kLTrigger = 0x10009,
		kRTrigger = 0x1000A,
		kStart = 0x10010,
		kBack = 0x10020,
		kLStick = 0x10040,
		kRStick = 0x10080,
		kLShoulder = 0x10100,
		kRShoulder = 0x10200,
		kAButton = 0x11000,
		kBButton = 0x12000,
		kXButton = 0x14000,
		kYButton = 0x18000,

		kWheelUp = 0x10800,
		kWheelDown = 0x10900,
	};

	class IDEvent;

	class __declspec(novtable) InputEvent
	{
	public:
		static constexpr auto RTTI{ RTTI::InputEvent };
		static constexpr auto VTABLE{ VTABLE::InputEvent };

		enum class HANDLED_RESULT : std::int32_t
		{
			kUnhandled,
			kContinue,
			kStop
		};

		virtual ~InputEvent() = default;  // 00

		// add
		virtual bool                 HasIDCode() const { return false; }  // 02
		virtual const BSFixedString& QUserEvent() const;                  // 03

		template <class T>
		[[nodiscard]] T* As() noexcept  //
			requires(std::derived_from<T, InputEvent> &&
					 !std::same_as<std::decay_t<T>, IDEvent>)
		{
			if (*eventType == T::TYPE) {
				return static_cast<T*>(this);
			} else {
				return nullptr;
			}
		}

		template <class T>
		[[nodiscard]] const T* As() const noexcept  //
			requires(std::derived_from<T, InputEvent> &&
					 !std::same_as<std::decay_t<T>, IDEvent>)
		{
			if (*eventType == T::TYPE) {
				return static_cast<const T*>(this);
			} else {
				return nullptr;
			}
		}

		template <class T>
		[[nodiscard]] T* As()  //
			requires(std::same_as<std::decay_t<T>, IDEvent>)
		{
			if (HasIDCode()) {
				return static_cast<T*>(this);
			} else {
				return nullptr;
			}
		}

		template <class T>
		[[nodiscard]] const T* As() const  //
			requires(std::same_as<std::decay_t<T>, IDEvent>)
		{
			if (HasIDCode()) {
				return static_cast<const T*>(this);
			} else {
				return nullptr;
			}
		}

		// members
		REX::EnumSet<INPUT_DEVICE, std::int32_t>     device{ INPUT_DEVICE::kNone };               // 08
		std::int32_t                                 deviceID{ 0 };                               // 0C
		REX::EnumSet<INPUT_EVENT_TYPE, std::int32_t> eventType{ INPUT_EVENT_TYPE::kNone };        // 10
		InputEvent*                                  next{ nullptr };                             // 18
		std::uint32_t                                timeCode{ static_cast<std::uint32_t>(-1) };  // 20
		REX::EnumSet<HANDLED_RESULT, std::int32_t>   handled{ HANDLED_RESULT::kUnhandled };       // 24
	};
	static_assert(sizeof(InputEvent) == 0x28);

	class __declspec(novtable) CharacterEvent :
		public InputEvent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::CharacterEvent };
		static constexpr auto VTABLE{ VTABLE::CharacterEvent };
		static constexpr auto TYPE{ INPUT_EVENT_TYPE::kChar };

		// NOLINTNEXTLINE(modernize-use-override)
		virtual ~CharacterEvent() = default;  // 00

		// members
		std::uint32_t charCode{ 0 };  // 28
	};
	static_assert(sizeof(CharacterEvent) == 0x30);

	extern template CharacterEvent*       InputEvent::As() noexcept;
	extern template const CharacterEvent* InputEvent::As() const noexcept;

	class __declspec(novtable) DeviceConnectEvent :
		public InputEvent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::DeviceConnectEvent };
		static constexpr auto VTABLE{ VTABLE::DeviceConnectEvent };
		static constexpr auto TYPE{ INPUT_EVENT_TYPE::kDeviceConnect };

		// NOLINTNEXTLINE(modernize-use-override)
		virtual ~DeviceConnectEvent() = default;  // 00

		// members
		bool connected{ true };  // 28
	};
	static_assert(sizeof(DeviceConnectEvent) == 0x30);

	extern template DeviceConnectEvent*       InputEvent::As() noexcept;
	extern template const DeviceConnectEvent* InputEvent::As() const noexcept;

	class __declspec(novtable) IDEvent :
		public InputEvent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::IDEvent };
		static constexpr auto VTABLE{ VTABLE::IDEvent };

		// NOLINTNEXTLINE(modernize-use-override)
		virtual ~IDEvent() = default;  // 00

		// override (InputEvent)
		bool HasIDCode() const override { return true; }  // 02

		const BSFixedString& QUserEvent() const override  // 03
		{
			if (!disabled) {
				return strUserEvent;
			}

			return "DISABLED"sv;
		}

		[[nodiscard]] const bool           QDisabled() const noexcept { return disabled; }
		[[nodiscard]] const std::uint32_t  QIDCode() const noexcept { return idCode; }
		[[nodiscard]] const BSFixedString& QRawUserEvent() const noexcept { return strUserEvent; }

		// members
		BSFixedString strUserEvent;       // 28
		std::int32_t  idCode{ -1 };       // 30
		bool          disabled{ false };  // 34
	};
	static_assert(sizeof(IDEvent) == 0x38);

	extern template IDEvent*       InputEvent::As();
	extern template const IDEvent* InputEvent::As() const;

	class __declspec(novtable) ButtonEvent :
		public IDEvent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ButtonEvent };
		static constexpr auto VTABLE{ VTABLE::ButtonEvent };
		static constexpr auto TYPE{ INPUT_EVENT_TYPE::kButton };

		// NOLINTNEXTLINE(modernize-use-override)
		virtual ~ButtonEvent() = default;  // 00

		[[nodiscard]] BS_BUTTON_CODE GetBSButtonCode() const noexcept
		{
			REX::EnumSet<BS_BUTTON_CODE> result{ static_cast<BS_BUTTON_CODE>(idCode) };
			switch (device.get()) {
			case INPUT_DEVICE::kGamepad:
				result.set(BS_BUTTON_CODE::kGamepad);
			default:
				return result.get();
			}
		}

		[[nodiscard]] float QAnalogValue() const noexcept { return value; }
		[[nodiscard]] bool  QHeldDown(float a_heldDownSecs) const noexcept { return value != 0.0 && a_heldDownSecs <= heldDownSecs; }
		[[nodiscard]] bool  QHeldDown() const noexcept { return value != 0.0 && heldDownSecs > 0.0F; }
		[[nodiscard]] float QHeldDownSecs() const noexcept { return heldDownSecs; }
		[[nodiscard]] bool  QJustPressed() const noexcept { return value != 0.0F && heldDownSecs == 0.0F; }
		[[nodiscard]] bool  QPressed() const noexcept { return value != 0.0F; }
		[[nodiscard]] bool  QReleased(float a_heldDownSecs) const noexcept { return value == 0.0F && a_heldDownSecs <= heldDownSecs; }
		[[nodiscard]] bool  QReleased() const noexcept { return value == 0.0F && heldDownSecs > 0.0F; }

		// members
		float value{ 0.0F };         // 38
		float heldDownSecs{ 0.0F };  // 3C
	};
	static_assert(sizeof(ButtonEvent) == 0x40);

	extern template ButtonEvent*       InputEvent::As() noexcept;
	extern template const ButtonEvent* InputEvent::As() const noexcept;

	class __declspec(novtable) CursorMoveEvent :
		public IDEvent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::CursorMoveEvent };
		static constexpr auto VTABLE{ VTABLE::CursorMoveEvent };
		static constexpr auto TYPE{ INPUT_EVENT_TYPE::kCursorMove };

		// NOLINTNEXTLINE(modernize-use-override)
		virtual ~CursorMoveEvent() = default;  // 00

		// members
		std::int32_t cursorPosX{ 0 };  // 38
		std::int32_t cursorPosY{ 0 };  // 3C
	};
	static_assert(sizeof(CursorMoveEvent) == 0x40);

	extern template CursorMoveEvent*       InputEvent::As() noexcept;
	extern template const CursorMoveEvent* InputEvent::As() const noexcept;

	class __declspec(novtable) KinectEvent :
		public IDEvent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::KinectEvent };
		static constexpr auto VTABLE{ VTABLE::KinectEvent };
		static constexpr auto TYPE{ INPUT_EVENT_TYPE::kKinect };

		// NOLINTNEXTLINE(modernize-use-override)
		virtual ~KinectEvent() = default;  // 00

		// members
		BSFixedString strHeard;  // 38
	};
	static_assert(sizeof(KinectEvent) == 0x40);

	extern template KinectEvent*       InputEvent::As() noexcept;
	extern template const KinectEvent* InputEvent::As() const noexcept;

	class __declspec(novtable) MouseMoveEvent :
		public IDEvent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::MouseMoveEvent };
		static constexpr auto VTABLE{ VTABLE::MouseMoveEvent };
		static constexpr auto TYPE{ INPUT_EVENT_TYPE::kMouseMove };

		// NOLINTNEXTLINE(modernize-use-override)
		virtual ~MouseMoveEvent() = default;  // 00

		// members
		std::int32_t mouseInputX{ 0 };  // 38
		std::int32_t mouseInputY{ 0 };  // 3C
	};
	static_assert(sizeof(MouseMoveEvent) == 0x40);

	extern template MouseMoveEvent*       InputEvent::As() noexcept;
	extern template const MouseMoveEvent* InputEvent::As() const noexcept;

	class __declspec(novtable) ThumbstickEvent :
		public IDEvent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ThumbstickEvent };
		static constexpr auto VTABLE{ VTABLE::ThumbstickEvent };
		static constexpr auto TYPE{ INPUT_EVENT_TYPE::kThumbstick };

		enum THUMBSTICK_ID : std::int32_t
		{
			kLeft = 0xB,
			kRight = 0xC,
		};

		// NOLINTNEXTLINE(modernize-use-override)
		virtual ~ThumbstickEvent() = default;  // 00

		// members
		float         xValue{ 0.0F };                   // 38
		float         yValue{ 0.0F };                   // 3C
		DIRECTION_VAL prevDir{ DIRECTION_VAL::kNone };  // 40
		DIRECTION_VAL currDir{ DIRECTION_VAL::kNone };  // 44
	};
	static_assert(sizeof(ThumbstickEvent) == 0x48);

	extern template ThumbstickEvent*       InputEvent::As() noexcept;
	extern template const ThumbstickEvent* InputEvent::As() const noexcept;
}
