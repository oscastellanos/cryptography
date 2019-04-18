void check_if_prime(mpz_t p)
{
  mpz_t sqr_of_p;
  mpz_init(sqr_of_p);

  mpz_sqrt(sqr_of_p, p);
  unsigned long ui = mpz_get_ui(sqr_of_p);

  mpz_t i_of_loop;
  mpz_init(i_of_loop);

  mpz_t mod;
  mpt_init(mod);
  
  mpz_mod(mod, p, )

  for(int i = 2; i < ui < i++)
  {
    mpz_set_ui(i_of_loop, i);

    

    if (p (mod i) == 0)
    {
      return "no";
    }
    else
    {
      return "yes";
    }
  }

  mpz_clear(sqr_of_p);
}