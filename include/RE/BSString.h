#pragma once


namespace RE
{
	class BSFixedString;


	class BSString
	{
	public:
		BSString();
		BSString(const BSString& a_str);
		BSString(BSString&& a_str);
		BSString(const char* a_str);
		~BSString();

		operator const char*() const;

		BSString&	operator=(const BSString& a_rhs);
		BSString&	operator=(BSString&& a_rhs);
		BSString&	operator=(const BSFixedString& str);
		BSString&	operator=(const char* a_rhs);

		friend bool	operator==(const BSString& a_lhs, const char* a_rhs) { return (a_lhs._data == a_rhs || _stricmp(a_lhs._data, a_rhs) == 0); }
		friend bool	operator!=(const BSString& a_lhs, const char* a_rhs) { return !(a_lhs == a_rhs); }
		friend bool	operator==(const char* a_lhs, const BSString& a_rhs) { return (a_rhs == a_lhs); }
		friend bool	operator!=(const char* a_lhs, const BSString& a_rhs) { return !(a_lhs == a_rhs); }
		friend bool	operator==(const BSString& a_lhs, const BSString& a_rhs) { return (a_lhs == a_rhs.c_str()); }
		friend bool	operator!=(const BSString& a_lhs, const BSString& a_rhs) { return !(a_lhs == a_rhs); }
		bool		operator==(const BSFixedString& a_rhs) const;
		bool		operator!=(const BSFixedString& a_rhs) const;

		UInt32		length() const;
		const char*	c_str() const;

	protected:
		bool		Set(const char* a_str, UInt32 a_len = 0);


		char*	_data;		// 00
		UInt16	_dataLen;	// 08
		UInt16	_bufLen;	// 0A
		UInt32	pad0C;		// 0C
	};
	STATIC_ASSERT(sizeof(BSString) == 0x10);
}