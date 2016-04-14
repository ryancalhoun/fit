#pragma once

namespace File
{
	enum Mode
	{
		Read = 0x0001,
		Write = 0x0002,
		Append = 0x0004,

		Create = 0x0008,
		CreateEx = 0x0010,

		Truncate = 0x0020,
	};
}

