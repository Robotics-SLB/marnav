#ifndef MARNAV__NMEA__PRDID__HPP
#define MARNAV__NMEA__PRDID__HPP

#include <marnav/nmea/sentence.hpp>
#include <marnav/utils/optional.hpp>

namespace marnav
{
namespace nmea
{
/// @brief PRDID - Pitch/Roll/Heading
///
/// @code
///        1      2      3      4
///        |      |      |      |
/// $PRDID,PPP.PP,RRR.RR,xxx.xx,*hh<CR><LF>
/// @endcode
///
/// Field Number:
///
/// 1. Pitch (degrees)
/// 2. Roll (degrees)
/// 3. Heading (degrees)
/// 4. Checksum
///
///
class prdid : public sentence
{
	friend class detail::factory;

public:
	constexpr static sentence_id ID = sentence_id::PRDID;
	constexpr static const char * TAG = "PRDID";

	prdid();
	prdid(const prdid &) = default;
	prdid & operator=(const prdid &) = default;
	prdid(prdid &&) = default;
	prdid & operator=(prdid &&) = default;

protected:
	prdid(talker talk, fields::const_iterator first, fields::const_iterator last);
	virtual void append_data_to(std::string &) const override;

private:
	utils::optional<double> pitch_;
	utils::optional<double> roll_;
	utils::optional<double> heading_;

public:
	decltype(pitch_) get_pitch() const
	{ 
		return pitch_;
	}
	decltype(roll_) get_roll() const
	{ 
		return roll_;
	}
	decltype(heading_) get_heading() const
	{ 
		return heading_;
	}
	void set_pitch(double t) noexcept { pitch_ = t; }
	void set_roll(double t) noexcept { roll_ = t; }
	void set_heading(double t) noexcept { heading_ = t; }
};
}
}

#endif
