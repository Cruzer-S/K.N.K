#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <wchar.h>

void show_locale_state(struct lconv *s)
{
#define S(M) printf(#M " = \"%s\"\n", s->M)
#define I(M) printf(#M " = %d \n", *s->M)
#define R(M) printf(#M " = %d \n", s->M)

	S(decimal_point);
	S(thousands_sep);
	I(grouping);
	
	S(mon_decimal_point);
	S(mon_thousands_sep);
	I(mon_grouping);
	S(positive_sign);
	S(negative_sign);
	S(currency_symbol);

	R(frac_digits);
	R(p_cs_precedes);
	R(n_cs_precedes);
	R(p_sep_by_space);
	R(n_sep_by_space);
	R(p_sign_posn);
	R(n_sign_posn);
	S(int_curr_symbol);
	R(int_frac_digits);
	R(int_p_cs_precedes);
	R(int_n_cs_precedes);
	R(int_p_sep_by_space);
	R(int_n_sep_by_space);
	R(int_p_sign_posn);
	R(int_n_sign_posn);

#undef S_STAT
#undef I_STAT
#undef R_STAT
}

int main(void)
#define PRT(X) printf("========================================\n"		\
					  "= " #X ": %s \n"									\
					  "========================================\n", X)  
{
	struct lconv *state;

	PRT(setlocale(LC_ALL, NULL));
	show_locale_state(localeconv());

	setlocale(LC_ALL, "ko_KR");
	PRT(setlocale(LC_ALL, NULL));
	show_locale_state(localeconv());

	setlocale(LC_ALL, "fi_FI");
	PRT(setlocale(LC_ALL, NULL));
	show_locale_state(localeconv());

	setlocale(LC_ALL, "en_US");
	PRT(setlocale(LC_ALL, NULL));
	show_locale_state(localeconv());


	return 0;
#undef PRT
}
