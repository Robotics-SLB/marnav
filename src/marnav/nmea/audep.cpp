#include "audep.hpp"
#include <marnav/nmea/io.hpp>

namespace marnav
{
namespace nmea
{
constexpr sentence_id audep::ID;
constexpr const char * audep::TAG;

audep::audep()
	: sentence(ID, TAG, talker_id::none)
{
}

audep::audep(talker talk, fields::const_iterator first, fields::const_iterator last)
	: sentence(ID, TAG, talk)
{
	if (std::distance(first, last) != 1)
		throw std::invalid_argument{"invalid number of fields in audep"};

	read(*(first + 0), depth_);
}

void audep::append_data_to(std::string & s) const
{
	append(s, to_string(depth_));
}
}
}
