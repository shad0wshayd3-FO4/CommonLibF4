#pragma once

namespace RE
{
	class __declspec(novtable) Setting
	{
	public:
		static constexpr auto RTTI{ RTTI::Setting };
		static constexpr auto VTABLE{ VTABLE::Setting };

		enum class SETTING_TYPE
		{
			kBinary,  // b
			kChar,    // c
			kUChar,   // h
			kInt,     // i
			kUInt,    // u
			kFloat,   // f
			kString,  // s/S
			kRGB,     // r
			kRGBA,    // a
			kNone
		};

		Setting(const char* a_key, char a_value)
		{
			_key = a_key;
			_value.c = a_value;
		}

		Setting(const char* a_key, bool a_value)
		{
			_key = a_key;
			_value.b = a_value;
		}

		Setting(const char* a_key, float a_value)
		{
			_key = a_key;
			_value.f = a_value;
		}

		Setting(const char* a_key, std::uint8_t a_value)
		{
			_key = a_key;
			_value.h = a_value;
		}

		Setting(const char* a_key, std::int32_t a_value)
		{
			_key = a_key;
			_value.i = a_value;
		}

		Setting(const char* a_key, const char* a_value)
		{
			_key = a_key;
			_value.s = _strdup(a_value);
		}

		Setting(const char* a_key, std::uint32_t a_value)
		{
			_key = a_key;
			_value.u = a_value;
		}

		virtual ~Setting()  // 00
		{
			if (_key && _key[0] == 'S') {
				free(const_cast<char*>(_key));
				_key = nullptr;
			}
		}

		// add
		[[nodiscard]] virtual bool IsPrefSetting() { return false; }  // 01

		F4_HEAP_REDEFINE_NEW(Setting);

		[[nodiscard]] bool GetBinary() const noexcept
		{
			assert(GetType() == SETTING_TYPE::kBinary);
			return _value.b;
		}

		[[nodiscard]] char GetChar() const noexcept
		{
			assert(GetType() == SETTING_TYPE::kChar);
			return _value.c;
		}

		[[nodiscard]] float GetFloat() const noexcept
		{
			assert(GetType() == SETTING_TYPE::kFloat);
			return _value.f;
		}

		[[nodiscard]] std::int32_t GetInt() const noexcept
		{
			assert(GetType() == SETTING_TYPE::kInt);
			return _value.i;
		}

		[[nodiscard]] std::string_view GetKey() const noexcept { return _key ? _key : ""sv; }

		[[nodiscard]] std::span<const std::uint8_t, 3> GetRGB() const noexcept
		{
			assert(GetType() == SETTING_TYPE::kRGB);
			return std::span<const std::uint8_t, 3>{
				reinterpret_cast<const std::uint8_t(&)[3]>(*std::addressof(_value.r))
			};
		}

		[[nodiscard]] std::span<const std::uint8_t, 4> GetRGBA() const noexcept
		{
			assert(GetType() == SETTING_TYPE::kRGBA);
			return std::span<const std::uint8_t, 4>{
				reinterpret_cast<const std::uint8_t(&)[4]>(*std::addressof(_value.a))
			};
		}

		[[nodiscard]] std::string_view GetString() const noexcept
		{
			assert(GetType() == SETTING_TYPE::kString);
			return _value.s ? _value.s : ""sv;
		}

		[[nodiscard]] SETTING_TYPE GetType() const noexcept
		{
			if (_key) {
				switch (_key[0]) {
				case 'b':
					return SETTING_TYPE::kBinary;
				case 'c':
					return SETTING_TYPE::kChar;
				case 'h':
					return SETTING_TYPE::kUChar;
				case 'i':
					return SETTING_TYPE::kInt;
				case 'u':
					return SETTING_TYPE::kUInt;
				case 'f':
					return SETTING_TYPE::kFloat;
				case 's':
				case 'S':
					return SETTING_TYPE::kString;
				case 'r':
					return SETTING_TYPE::kRGB;
				case 'a':
					return SETTING_TYPE::kRGBA;
				default:
					return SETTING_TYPE::kNone;
				}
			}
			else {
				return SETTING_TYPE::kNone;
			}
		}

		[[nodiscard]] std::uint8_t GetUChar() const noexcept
		{
			assert(GetType() == SETTING_TYPE::kUChar);
			return _value.h;
		}

		[[nodiscard]] std::uint32_t GetUInt() const noexcept
		{
			assert(GetType() == SETTING_TYPE::kUInt);
			return _value.u;
		}

		void SetBinary(bool a_value) noexcept
		{
			assert(GetType() == SETTING_TYPE::kBinary);
			_value.b = a_value;
		}

		void SetChar(char a_value) noexcept
		{
			assert(GetType() == SETTING_TYPE::kChar);
			_value.c = a_value;
		}

		void SetFloat(float a_value) noexcept
		{
			assert(GetType() == SETTING_TYPE::kFloat);
			_value.f = a_value;
		}

		void SetInt(std::int32_t a_value) noexcept
		{
			assert(GetType() == SETTING_TYPE::kInt);
			_value.i = a_value;
		}

		void SetRGB(std::span<const std::uint8_t, 3> a_value) noexcept
		{
			assert(GetType() == SETTING_TYPE::kRGB);
			std::copy(
				a_value.begin(),
				a_value.end(),
				std::addressof(_value.r));
		}

		void SetRGBA(std::span<const std::uint8_t, 4> a_value) noexcept
		{
			assert(GetType() == SETTING_TYPE::kRGBA);
			std::copy(
				a_value.begin(),
				a_value.end(),
				std::addressof(_value.r));
		}

		void SetString(char* a_value) noexcept
		{
			assert(GetType() == SETTING_TYPE::kString);
			_value.s = a_value;
		}

		void SetUChar(std::uint8_t a_value) noexcept
		{
			assert(GetType() == SETTING_TYPE::kUChar);
			_value.h = a_value;
		}

		void SetUInt(std::uint32_t a_value) noexcept
		{
			assert(GetType() == SETTING_TYPE::kUInt);
			_value.u = a_value;
		}

	private:
		// members
		SETTING_VALUE _value;  // 08
		const char* _key;    // 10
	};
	static_assert(sizeof(Setting) == 0x18);

	template <class T>
	class __declspec(novtable) SettingT :
		public Setting  // 00
	{
	public:
	};

	class GameSettingCollection;
	class INIPrefSettingCollection;
	class INISettingCollection;
	class LipSynchroSettingCollection;
	class RegSettingCollection;

	extern template class SettingT<GameSettingCollection>;
	extern template class SettingT<INIPrefSettingCollection>;
	extern template class SettingT<INISettingCollection>;
	extern template class SettingT<LipSynchroSettingCollection>;
	extern template class SettingT<RegSettingCollection>;
}
