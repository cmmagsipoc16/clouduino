/* Automatically generated code; do not modify directly. */

#include <stddef.h>
#include <stdint.h>
#ifdef ESP8266
	#include <pgmspace.h>
#endif

typedef struct {
	uint32_t *dp;
	uint32_t *rp;
	const unsigned char *ip;
} t0_context;

static uint32_t
t0_parse7E_unsigned(const unsigned char **p)
{
	uint32_t x;

	x = 0;
	for (;;) {
		unsigned y;

#ifdef ESP8266
		y = pgm_read_byte((*p)++);
#else
		y = *(*p) ++;
#endif
		x = (x << 7) | (uint32_t)(y & 0x7F);
		if (y < 0x80) {
			return x;
		}
	}
}

static int32_t
t0_parse7E_signed(const unsigned char **p)
{
	int neg;
	uint32_t x;

#ifdef ESP8266
	neg = (pgm_read_byte(*p) >> 6) & 1;
#else
	neg = ((**p) >> 6) & 1;
#endif
	x = (uint32_t)-neg;
	for (;;) {
		unsigned y;

#ifdef ESP8266
		y = pgm_read_byte((*p)++);
#else
		y = *(*p) ++;
#endif
		x = (x << 7) | (uint32_t)(y & 0x7F);
		if (y < 0x80) {
			if (neg) {
				return -(int32_t)~x - 1;
			} else {
				return (int32_t)x;
			}
		}
	}
}

#define T0_VBYTE(x, n)   (unsigned char)((((uint32_t)(x) >> (n)) & 0x7F) | 0x80)
#define T0_FBYTE(x, n)   (unsigned char)(((uint32_t)(x) >> (n)) & 0x7F)
#define T0_SBYTE(x)      (unsigned char)((((uint32_t)(x) >> 28) + 0xF8) ^ 0xF8)
#define T0_INT1(x)       T0_FBYTE(x, 0)
#define T0_INT2(x)       T0_VBYTE(x, 7), T0_FBYTE(x, 0)
#define T0_INT3(x)       T0_VBYTE(x, 14), T0_VBYTE(x, 7), T0_FBYTE(x, 0)
#define T0_INT4(x)       T0_VBYTE(x, 21), T0_VBYTE(x, 14), T0_VBYTE(x, 7), T0_FBYTE(x, 0)
#define T0_INT5(x)       T0_SBYTE(x), T0_VBYTE(x, 21), T0_VBYTE(x, 14), T0_VBYTE(x, 7), T0_FBYTE(x, 0)

/* static const unsigned char t0_datablock[]; */


void br_pkey_decoder_init_main(void *t0ctx);

void br_pkey_decoder_run(void *t0ctx);



#include "inner.h"





#include "inner.h"

#define CTX   ((br_pkey_decoder_context *)(void *)((unsigned char *)t0ctx - offsetof(br_pkey_decoder_context, cpu)))
#define CONTEXT_NAME   br_pkey_decoder_context

/* see bearssl_x509.h */
void
br_pkey_decoder_init(br_pkey_decoder_context *ctx)
{
	memset(ctx, 0, sizeof *ctx);
	ctx->cpu.dp = &ctx->dp_stack[0];
	ctx->cpu.rp = &ctx->rp_stack[0];
	br_pkey_decoder_init_main(&ctx->cpu);
	br_pkey_decoder_run(&ctx->cpu);
}

/* see bearssl_x509.h */
void
br_pkey_decoder_push(br_pkey_decoder_context *ctx,
	const void *data, size_t len)
{
	ctx->hbuf = data;
	ctx->hlen = len;
	br_pkey_decoder_run(&ctx->cpu);
}



#ifdef ESP8266
static const unsigned char t0_datablock[] PROGMEM = {
#else
static const unsigned char t0_datablock[] = {
#endif

	0x00, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01, 0x01, 0x01, 0x07,
	0x2A, 0x86, 0x48, 0xCE, 0x3D, 0x02, 0x01, 0x08, 0x2A, 0x86, 0x48, 0xCE,
	0x3D, 0x03, 0x01, 0x07, 0x05, 0x2B, 0x81, 0x04, 0x00, 0x22, 0x05, 0x2B,
	0x81, 0x04, 0x00, 0x23
};

#ifdef ESP8266
static const unsigned char t0_codeblock[] PROGMEM = {
#else
static const unsigned char t0_codeblock[] = {
#endif
	0x00, 0x01, 0x01, 0x07, 0x00, 0x00, 0x01, 0x01, 0x08, 0x00, 0x00, 0x12,
	0x12, 0x00, 0x00, 0x01, T0_INT1(BR_ERR_X509_BAD_TAG_CLASS), 0x00, 0x00,
	0x01, T0_INT1(BR_ERR_X509_BAD_TAG_VALUE), 0x00, 0x00, 0x01,
	T0_INT1(BR_ERR_X509_EXTRA_ELEMENT), 0x00, 0x00, 0x01,
	T0_INT1(BR_ERR_X509_INDEFINITE_LENGTH), 0x00, 0x00, 0x01,
	T0_INT1(BR_ERR_X509_INNER_TRUNC), 0x00, 0x00, 0x01,
	T0_INT1(BR_ERR_X509_LIMIT_EXCEEDED), 0x00, 0x00, 0x01,
	T0_INT1(BR_ERR_X509_NOT_CONSTRUCTED), 0x00, 0x00, 0x01,
	T0_INT1(BR_ERR_X509_NOT_PRIMITIVE), 0x00, 0x00, 0x01,
	T0_INT1(BR_ERR_X509_OVERFLOW), 0x00, 0x00, 0x01,
	T0_INT1(BR_ERR_X509_UNEXPECTED), 0x00, 0x00, 0x01,
	T0_INT1(BR_ERR_X509_UNSUPPORTED), 0x00, 0x00, 0x01,
	T0_INT1(BR_KEYTYPE_EC), 0x00, 0x00, 0x01, T0_INT1(BR_KEYTYPE_RSA),
	0x00, 0x00, 0x01, T0_INT2(offsetof(CONTEXT_NAME, key_data)), 0x00,
	0x00, 0x01, T0_INT2(offsetof(CONTEXT_NAME, key_type)), 0x00, 0x00,
	0x2F, 0x43, 0x00, 0x00, 0x01, T0_INT2(offsetof(CONTEXT_NAME, pad)),
	0x00, 0x00, 0x01, 0x13, 0x00, 0x00, 0x01, 0x1C, 0x00, 0x00, 0x01, 0x22,
	0x00, 0x00, 0x05, 0x02, 0x28, 0x15, 0x00, 0x00, 0x06, 0x02, 0x29, 0x15,
	0x00, 0x00, 0x01, 0x10, 0x39, 0x00, 0x00, 0x0C, 0x05, 0x02, 0x2B, 0x15,
	0x36, 0x00, 0x00, 0x0C, 0x05, 0x02, 0x2B, 0x15, 0x37, 0x00, 0x00, 0x06,
	0x02, 0x24, 0x15, 0x00, 0x01, 0x03, 0x00, 0x51, 0x06, 0x02, 0x2C, 0x15,
	0x50, 0x01, 0x04, 0x3A, 0x02, 0x00, 0x3D, 0x00, 0x02, 0x03, 0x00, 0x13,
	0x03, 0x01, 0x02, 0x01, 0x43, 0x0D, 0x06, 0x02, 0x2C, 0x15, 0x02, 0x01,
	0x2F, 0x47, 0x12, 0x01, 0x00, 0x02, 0x00, 0x05, 0x02, 0x2C, 0x15, 0x02,
	0x00, 0x02, 0x01, 0x1B, 0x00, 0x02, 0x4D, 0x46, 0x05, 0x02, 0x2C, 0x15,
	0x53, 0x14, 0x06, 0x07, 0x55, 0x01, 0x7F, 0x03, 0x01, 0x04, 0x16, 0x42,
	0x14, 0x06, 0x10, 0x01, 0x00, 0x03, 0x01, 0x13, 0x06, 0x03, 0x48, 0x04,
	0x02, 0x01, 0x00, 0x03, 0x00, 0x04, 0x02, 0x2C, 0x15, 0x3B, 0x50, 0x01,
	0x03, 0x3A, 0x4D, 0x02, 0x01, 0x06, 0x03, 0x3F, 0x04, 0x03, 0x02, 0x00,
	0x3C, 0x3B, 0x55, 0x02, 0x01, 0x06, 0x03, 0x2E, 0x04, 0x01, 0x2D, 0x00,
	0x00, 0x51, 0x06, 0x02, 0x2C, 0x15, 0x4E, 0x40, 0x3B, 0x00, 0x03, 0x31,
	0x49, 0x13, 0x13, 0x03, 0x00, 0x03, 0x01, 0x4B, 0x03, 0x02, 0x02, 0x00,
	0x02, 0x02, 0x1C, 0x00, 0x00, 0x17, 0x17, 0x00, 0x00, 0x01, 0x0B, 0x00,
	0x00, 0x01, T0_INT2(3 * BR_X509_BUFSIZE_KEY), 0x00, 0x01, 0x01, 0x87,
	0xFF, 0xFF, 0x7F, 0x4E, 0x50, 0x01, 0x02, 0x17, 0x0C, 0x06, 0x06, 0x12,
	0x37, 0x40, 0x2E, 0x04, 0x1C, 0x01, 0x04, 0x17, 0x0C, 0x06, 0x08, 0x12,
	0x37, 0x01, 0x00, 0x3D, 0x2D, 0x04, 0x0E, 0x01, 0x10, 0x17, 0x0C, 0x06,
	0x05, 0x12, 0x36, 0x3E, 0x04, 0x03, 0x2C, 0x15, 0x12, 0x03, 0x00, 0x3B,
	0x02, 0x00, 0x30, 0x1D, 0x52, 0x24, 0x15, 0x00, 0x01, 0x41, 0x0A, 0x06,
	0x02, 0x26, 0x15, 0x13, 0x03, 0x00, 0x08, 0x02, 0x00, 0x00, 0x00, 0x50,
	0x01, 0x06, 0x3A, 0x4F, 0x00, 0x00, 0x1E, 0x13, 0x06, 0x07, 0x18, 0x13,
	0x06, 0x01, 0x11, 0x04, 0x76, 0x21, 0x00, 0x00, 0x46, 0x05, 0x02, 0x2C,
	0x15, 0x33, 0x14, 0x06, 0x04, 0x01, 0x17, 0x04, 0x12, 0x34, 0x14, 0x06,
	0x04, 0x01, 0x18, 0x04, 0x0A, 0x35, 0x14, 0x06, 0x04, 0x01, 0x19, 0x04,
	0x02, 0x2C, 0x15, 0x00, 0x00, 0x1A, 0x50, 0x01, 0x02, 0x3A, 0x09, 0x4A,
	0x00, 0x03, 0x13, 0x03, 0x00, 0x03, 0x01, 0x03, 0x02, 0x4D, 0x51, 0x13,
	0x01, 0x81, 0x00, 0x0E, 0x06, 0x02, 0x2A, 0x15, 0x13, 0x01, 0x00, 0x0C,
	0x06, 0x0B, 0x12, 0x13, 0x05, 0x04, 0x12, 0x01, 0x00, 0x00, 0x51, 0x04,
	0x6F, 0x02, 0x01, 0x13, 0x05, 0x02, 0x27, 0x15, 0x20, 0x03, 0x01, 0x02,
	0x02, 0x1D, 0x02, 0x02, 0x1F, 0x03, 0x02, 0x13, 0x06, 0x03, 0x51, 0x04,
	0x68, 0x12, 0x02, 0x00, 0x02, 0x01, 0x08, 0x00, 0x00, 0x13, 0x31, 0x1A,
	0x08, 0x1E, 0x1A, 0x07, 0x1E, 0x49, 0x00, 0x01, 0x51, 0x13, 0x01, 0x81,
	0x00, 0x0A, 0x06, 0x01, 0x00, 0x01, 0x81, 0x00, 0x08, 0x13, 0x05, 0x02,
	0x25, 0x15, 0x03, 0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00, 0x0D, 0x06,
	0x19, 0x02, 0x00, 0x20, 0x03, 0x00, 0x13, 0x01, 0x83, 0xFF, 0xFF, 0x7F,
	0x0D, 0x06, 0x02, 0x26, 0x15, 0x01, 0x08, 0x0B, 0x1E, 0x51, 0x1A, 0x07,
	0x04, 0x60, 0x00, 0x00, 0x4C, 0x45, 0x00, 0x00, 0x50, 0x38, 0x4D, 0x00,
	0x00, 0x4D, 0x13, 0x01, 0x81, 0x7F, 0x0D, 0x06, 0x08, 0x54, 0x01, 0x00,
	0x32, 0x1D, 0x01, 0x00, 0x00, 0x13, 0x32, 0x1D, 0x32, 0x1F, 0x47, 0x01,
	0x7F, 0x00, 0x01, 0x51, 0x03, 0x00, 0x02, 0x00, 0x01, 0x05, 0x0F, 0x01,
	0x01, 0x10, 0x16, 0x02, 0x00, 0x01, 0x06, 0x0F, 0x13, 0x01, 0x01, 0x10,
	0x06, 0x02, 0x22, 0x15, 0x01, 0x04, 0x0B, 0x02, 0x00, 0x01, 0x1F, 0x10,
	0x13, 0x01, 0x1F, 0x0C, 0x06, 0x02, 0x23, 0x15, 0x07, 0x00, 0x00, 0x13,
	0x05, 0x02, 0x26, 0x15, 0x20, 0x52, 0x00, 0x00, 0x19, 0x13, 0x01, 0x00,
	0x0E, 0x06, 0x01, 0x00, 0x12, 0x11, 0x04, 0x74, 0x00, 0x01, 0x01, 0x00,
	0x00, 0x55, 0x12, 0x00, 0x00, 0x13, 0x06, 0x07, 0x56, 0x13, 0x06, 0x01,
	0x11, 0x04, 0x76, 0x00, 0x00, 0x01, 0x00, 0x17, 0x18, 0x09, 0x21, 0x00
};

#ifdef ESP8266
static const uint16_t t0_caddr[] PROGMEM = {
#else
static const uint16_t t0_caddr[] = {
#endif
	0,
	5,
	10,
	14,
	18,
	22,
	26,
	30,
	34,
	38,
	42,
	46,
	50,
	54,
	58,
	62,
	66,
	71,
	76,
	80,
	85,
	89,
	93,
	97,
	103,
	109,
	114,
	122,
	130,
	136,
	152,
	185,
	252,
	262,
	280,
	284,
	288,
	293,
	352,
	366,
	373,
	387,
	420,
	429,
	496,
	507,
	563,
	567,
	572,
	598,
	642,
	651,
	664,
	668,
	672,
	684
};

#define T0_INTERPRETED   31

#ifdef ESP8266
#define T0_ENTER(ip, rp, slot)   do { \
		const unsigned char *t0_newip; \
		uint32_t t0_lnum; \
		t0_newip = &t0_codeblock[pgm_read_word(&t0_caddr[(slot) - T0_INTERPRETED])]; \
		t0_lnum = t0_parse7E_unsigned(&t0_newip); \
		(rp) += t0_lnum; \
		*((rp) ++) = (uint32_t)((ip) - &t0_codeblock[0]) + (t0_lnum << 16); \
		(ip) = t0_newip; \
	} while (0)
#else
#define T0_ENTER(ip, rp, slot)   do { \
		const unsigned char *t0_newip; \
		uint32_t t0_lnum; \
		t0_newip = &t0_codeblock[t0_caddr[(slot) - T0_INTERPRETED]]; \
		t0_lnum = t0_parse7E_unsigned(&t0_newip); \
		(rp) += t0_lnum; \
		*((rp) ++) = (uint32_t)((ip) - &t0_codeblock[0]) + (t0_lnum << 16); \
		(ip) = t0_newip; \
	} while (0)
#endif

#define T0_DEFENTRY(name, slot) \
void \
name(void *ctx) \
{ \
	t0_context *t0ctx = ctx; \
	t0ctx->ip = &t0_codeblock[0]; \
	T0_ENTER(t0ctx->ip, t0ctx->rp, slot); \
}

T0_DEFENTRY(br_pkey_decoder_init_main, 68)

#ifdef ESP8266
#define T0_NEXT(t0ipp)   (pgm_read_byte((*t0ipp)++))
#else
#define T0_NEXT(t0ipp)   (*(*(t0ipp)) ++)
#endif

void
br_pkey_decoder_run(void *t0ctx)
{
	uint32_t *dp, *rp;
	const unsigned char *ip;

#define T0_LOCAL(x)    (*(rp - 2 - (x)))
#define T0_POP()       (*-- dp)
#define T0_POPi()      (*(int32_t *)(-- dp))
#define T0_PEEK(x)     (*(dp - 1 - (x)))
#define T0_PEEKi(x)    (*(int32_t *)(dp - 1 - (x)))
#define T0_PUSH(v)     do { *dp = (v); dp ++; } while (0)
#define T0_PUSHi(v)    do { *(int32_t *)dp = (v); dp ++; } while (0)
#define T0_RPOP()      (*-- rp)
#define T0_RPOPi()     (*(int32_t *)(-- rp))
#define T0_RPUSH(v)    do { *rp = (v); rp ++; } while (0)
#define T0_RPUSHi(v)   do { *(int32_t *)rp = (v); rp ++; } while (0)
#define T0_ROLL(x)     do { \
	size_t t0len = (size_t)(x); \
	uint32_t t0tmp = *(dp - 1 - t0len); \
	memmove(dp - t0len - 1, dp - t0len, t0len * sizeof *dp); \
	*(dp - 1) = t0tmp; \
} while (0)
#define T0_SWAP()      do { \
	uint32_t t0tmp = *(dp - 2); \
	*(dp - 2) = *(dp - 1); \
	*(dp - 1) = t0tmp; \
} while (0)
#define T0_ROT()       do { \
	uint32_t t0tmp = *(dp - 3); \
	*(dp - 3) = *(dp - 2); \
	*(dp - 2) = *(dp - 1); \
	*(dp - 1) = t0tmp; \
} while (0)
#define T0_NROT()       do { \
	uint32_t t0tmp = *(dp - 1); \
	*(dp - 1) = *(dp - 2); \
	*(dp - 2) = *(dp - 3); \
	*(dp - 3) = t0tmp; \
} while (0)
#define T0_PICK(x)      do { \
	uint32_t t0depth = (x); \
	T0_PUSH(T0_PEEK(t0depth)); \
} while (0)
#define T0_CO()         do { \
	goto t0_exit; \
} while (0)
#define T0_RET()        goto t0_next

	dp = ((t0_context *)t0ctx)->dp;
	rp = ((t0_context *)t0ctx)->rp;
	ip = ((t0_context *)t0ctx)->ip;
	goto t0_next;
	for (;;) {
		uint32_t t0x;

	t0_next:
		t0x = T0_NEXT(&ip);
		if (t0x < T0_INTERPRETED) {
			switch (t0x) {
				int32_t t0off;

			case 0: /* ret */
				t0x = T0_RPOP();
				rp -= (t0x >> 16);
				t0x &= 0xFFFF;
				if (t0x == 0) {
					ip = NULL;
					goto t0_exit;
				}
				ip = &t0_codeblock[t0x];
				break;
			case 1: /* literal constant */
				T0_PUSHi(t0_parse7E_signed(&ip));
				break;
			case 2: /* read local */
				T0_PUSH(T0_LOCAL(t0_parse7E_unsigned(&ip)));
				break;
			case 3: /* write local */
				T0_LOCAL(t0_parse7E_unsigned(&ip)) = T0_POP();
				break;
			case 4: /* jump */
				t0off = t0_parse7E_signed(&ip);
				ip += t0off;
				break;
			case 5: /* jump if */
				t0off = t0_parse7E_signed(&ip);
				if (T0_POP()) {
					ip += t0off;
				}
				break;
			case 6: /* jump if not */
				t0off = t0_parse7E_signed(&ip);
				if (!T0_POP()) {
					ip += t0off;
				}
				break;
			case 7: {
				/* + */

	uint32_t b = T0_POP();
	uint32_t a = T0_POP();
	T0_PUSH(a + b);

				}
				break;
			case 8: {
				/* - */

	uint32_t b = T0_POP();
	uint32_t a = T0_POP();
	T0_PUSH(a - b);

				}
				break;
			case 9: {
				/* -rot */
 T0_NROT(); 
				}
				break;
			case 10: {
				/* < */

	int32_t b = T0_POPi();
	int32_t a = T0_POPi();
	T0_PUSH(-(uint32_t)(a < b));

				}
				break;
			case 11: {
				/* << */

	int c = (int)T0_POPi();
	uint32_t x = T0_POP();
	T0_PUSH(x << c);

				}
				break;
			case 12: {
				/* = */

	uint32_t b = T0_POP();
	uint32_t a = T0_POP();
	T0_PUSH(-(uint32_t)(a == b));

				}
				break;
			case 13: {
				/* > */

	int32_t b = T0_POPi();
	int32_t a = T0_POPi();
	T0_PUSH(-(uint32_t)(a > b));

				}
				break;
			case 14: {
				/* >= */

	int32_t b = T0_POPi();
	int32_t a = T0_POPi();
	T0_PUSH(-(uint32_t)(a >= b));

				}
				break;
			case 15: {
				/* >> */

	int c = (int)T0_POPi();
	int32_t x = T0_POPi();
	T0_PUSHi(x >> c);

				}
				break;
			case 16: {
				/* and */

	uint32_t b = T0_POP();
	uint32_t a = T0_POP();
	T0_PUSH(a & b);

				}
				break;
			case 17: {
				/* co */
 T0_CO(); 
				}
				break;
			case 18: {
				/* drop */
 (void)T0_POP(); 
				}
				break;
			case 19: {
				/* dup */
 T0_PUSH(T0_PEEK(0)); 
				}
				break;
			case 20: {
				/* eqOID */

	const unsigned char *a2 = &t0_datablock[T0_POP()];
	const unsigned char *a1 = &CTX->pad[0];
	size_t len = a1[0];
	int x;
#ifdef ESP8266
	if (len == pgm_read_byte(&a2[0])) {
		x = -(memcmp_P(a1 + 1, a2 + 1, len) == 0);
	} else {
		x = 0;
	}
#else
	if (len == a2[0]) {
		x = -(memcmp(a1 + 1, a2 + 1, len) == 0);
	} else {
		x = 0;
	}
#endif
	T0_PUSH((uint32_t)x);

				}
				break;
			case 21: {
				/* fail */

	CTX->err = T0_POPi();
	T0_CO();

				}
				break;
			case 22: {
				/* neg */

	uint32_t a = T0_POP();
	T0_PUSH(-a);

				}
				break;
			case 23: {
				/* over */
 T0_PUSH(T0_PEEK(1)); 
				}
				break;
			case 24: {
				/* read-blob-inner */

	uint32_t len = T0_POP();
	uint32_t addr = T0_POP();
	size_t clen = CTX->hlen;
	if (clen > len) {
		clen = (size_t)len;
	}
	if (addr != 0) {
#ifdef ESP8266
		memcpy_P((unsigned char *)CTX + addr, CTX->hbuf, clen);
#else
		memcpy((unsigned char *)CTX + addr, CTX->hbuf, clen);
#endif
	}
	CTX->hbuf += clen;
	CTX->hlen -= clen;
	T0_PUSH(addr + clen);
	T0_PUSH(len - clen);

				}
				break;
			case 25: {
				/* read8-low */

	if (CTX->hlen == 0) {
		T0_PUSHi(-1);
	} else {
		CTX->hlen --;
#ifdef ESP8266
		T0_PUSH(pgm_read_byte(CTX->hbuf ++));
#else
		T0_PUSH(*CTX->hbuf ++);
#endif
	}

				}
				break;
			case 26: {
				/* rot */
 T0_ROT(); 
				}
				break;
			case 27: {
				/* set-ec-key */

	size_t qlen = T0_POP();
	uint32_t curve = T0_POP();
	CTX->key.ec.curve = curve;
	CTX->key.ec.q = CTX->key_data;
	CTX->key.ec.qlen = qlen;

				}
				break;
			case 28: {
				/* set-rsa-key */

	size_t elen = T0_POP();
	size_t nlen = T0_POP();

	CTX->key.rsa.n = CTX->key_data;
	CTX->key.rsa.nlen = nlen;
	CTX->key.rsa.e = CTX->key_data + nlen;
	CTX->key.rsa.elen = elen;

				}
				break;
			case 29: {
				/* set8 */

	uint32_t addr = T0_POP();
	*((unsigned char *)CTX + addr) = (unsigned char)T0_POP();

				}
				break;
			case 30: {
				/* swap */
 T0_SWAP(); 
				}
				break;
			}

		} else {
			T0_ENTER(ip, rp, t0x);
		}
	}
t0_exit:
	((t0_context *)t0ctx)->dp = dp;
	((t0_context *)t0ctx)->rp = rp;
	((t0_context *)t0ctx)->ip = ip;
}
