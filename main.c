#define HELLO_MAMBO "Hello Mambo!\n"
#define HELLO_OPAL "Hello OPAL!\n"

typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long u64;

static inline u16
swab16(u16 x)
{
	return  ((x & (u16)0x00ffU) << 8) |
		((x & (u16)0xff00U) >> 8);
}

static inline u32
swab32(u32 x)
{
	return  ((x & (u32)0x000000ffUL) << 24) |
		((x & (u32)0x0000ff00UL) <<  8) |
		((x & (u32)0x00ff0000UL) >>  8) |
		((x & (u32)0xff000000UL) >> 24);
}

static inline u64
swab64(u64 x)
{
	return  (u64)((x & (u64)0x00000000000000ffULL) << 56) |
		(u64)((x & (u64)0x000000000000ff00ULL) << 40) |
		(u64)((x & (u64)0x0000000000ff0000ULL) << 24) |
		(u64)((x & (u64)0x00000000ff000000ULL) <<  8) |
		(u64)((x & (u64)0x000000ff00000000ULL) >>  8) |
		(u64)((x & (u64)0x0000ff0000000000ULL) >> 24) |
		(u64)((x & (u64)0x00ff000000000000ULL) >> 40) |
		(u64)((x & (u64)0xff00000000000000ULL) >> 56);
}

void
c_main(u64 dt_base)
{
	u64 len = swab64(sizeof(HELLO_OPAL));

	mambo_write(HELLO_MAMBO, sizeof(HELLO_MAMBO));
	opal_write(HELLO_OPAL, &len);
}
