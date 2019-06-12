#ifndef MARNAV__NMEA__AUDEP__HPP
#define MARNAV__NMEA__AUDEP__HPP

#include <marnav/nmea/sentence.hpp>
#include <marnav/utils/optional.hpp>

namespace marnav
{
namespace nmea
{
/// @brief AUDEP - Depth
///
/// @code
///        1      2   
///        |      |   
/// AUDEP,DDD.DD,*hh<CR><LF>
/// @endcode
///
/// Field Number:
///
/// 1. Depth (m)
/// 2. Checksum
///
///
class audep : public sentence
{
	friend class detail::factory;

public:
	constexpr static sentence_id ID = sentence_id::AUDEP;
	constexpr static const char * TAG = "AUDEP";

	audep();
	audep(const audep &) = default;
	audep & operator=(const audep &) = default;
	audep(audep &&) = default;
	audep & operator=(audep &&) = default;

protected:
	audep(talker talk, fields::const_iterator first, fields::const_iterator last);
	virtual void append_data_to(std::string &) const override;

private:
	utils::optional<double> depth_;

public:
	decltype(depth_) get_depth() const
	{ 
		return depth_;
	}
	void set_depth(double t) noexcept { depth_ = t; }
};
}
}

#endif
