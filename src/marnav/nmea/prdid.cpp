#include "prdid.hpp"
#include <marnav/nmea/io.hpp>

namespace marnav
{
namespace nmea
{
constexpr sentence_id prdid::ID;
constexpr const char * prdid::TAG;

prdid::prdid()
	: sentence(ID, TAG, talker_id::none)
{
}

prdid::prdid(talker talk, fields::const_iterator first, fields::const_iterator last)
	: sentence(ID, TAG, talk)
{
	if (std::distance(first, last) != 3)
		throw std::invalid_argument{"invalid number of fields in prdid"};

	read(*(first + 0), pitch_);
	read(*(first + 1), roll_);
	read(*(first + 2), heading_);
}

void prdid::append_data_to(std::string & s) const
{
	append(s, to_string(pitch_));
	append(s, to_string(roll_));
	append(s, to_string(heading_));
}
}
}
