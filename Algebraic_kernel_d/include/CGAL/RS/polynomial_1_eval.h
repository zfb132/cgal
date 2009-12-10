// Copyright (c) 2006-2008 Inria Lorraine (France). All rights reserved.
// 
// This file is part of CGAL (www.cgal.org); you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public License as
// published by the Free Software Foundation; version 2.1 of the License.
// See the file LICENSE.LGPL distributed with CGAL.
// 
// Licensees holding a valid commercial license may use this file in
// accordance with the commercial license agreement provided with the software.
// 
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
// 
// $URL$
// $Id$
// 
// Author: Luis Pe�aranda <luis.penaranda@loria.fr>

#ifndef CGAL_RS_POLYNOMIAL_1_EVAL_H
#define CGAL_RS_POLYNOMIAL_1_EVAL_H

namespace CGAL{

// This function uses the Horner's method to evaluate the polynomial.
inline
void RS_polynomial_1::eval_dyadic(dyadic_ptr h,dyadic_srcptr x)const{
        int d=get_degree();
        dyadic_set_z(h,leading_coefficient());
        for(int i=1;i<d+1;++i){
                dyadic_mul(h,h,x);
                dyadic_add_z(h,h,coef(d-i));
        }
}

inline
void RS_polynomial_1::eval_mpfr(mpfr_ptr result,mpfr_srcptr xcoord)const{
        // mpfr and dyadic are now the same struct
        this->eval_dyadic(result,xcoord);
}

inline
void RS_polynomial_1::inexact_eval_mpfr(mpfr_ptr h,mpfr_srcptr x)const{
        int d=get_degree();
        mpfr_set_z(h,leading_coefficient(),GMP_RNDN);
        for(int i=1;i<d+1;++i){
                mpfr_mul(h,h,x,GMP_RNDN);
                mpfr_add_z(h,h,coef(d-i),GMP_RNDN);
        }
}

// Evaluation of a polynomial in a given interval using Horner's rule.
// y=p(x), y must be already initialized.
inline
void RS_polynomial_1::eval_mpfi(mpfi_ptr y,mpfi_srcptr x)const{
        int d=get_degree();
        mpfi_set_z(y,leading_coefficient());
        for(int i=1;i<d+1;++i){
                mpfi_mul(y,y,x);
                mpfi_add_z(y,y,coef(d-i));
        }
}

// Sign determination is essentially the same that evaluation. As we only
// want to know the sign, we don't finish the Horner's evaluation.
inline
Sign RS_polynomial_1::sign_dyadic(dyadic_srcptr x)const{
        int d,s;
        dyadic_t h;
        if(!(d=get_degree())){
                s=mpz_sgn(coef(0));
                return(s?(s>0?POSITIVE:NEGATIVE):ZERO);
        }
        dyadic_init_set_z(h,leading_coefficient());
        for(int i=1;i<d;++i){
                dyadic_mul(h,h,x);
                dyadic_add_z(h,h,coef(d-i));
        }
        dyadic_mul(h,h,x);
        dyadic_neg(h,h);
        s=mpfr_cmp_z(h,coef(0));
        return(s?(s>0?NEGATIVE:POSITIVE):ZERO);
}

inline
Sign RS_polynomial_1::sign_mpfr(mpfr_srcptr x)const{
        // no need to convert mpfr to dyadic anymore:
        // they are now the same struct
        return sign_dyadic(x);
}

// calculates the sign of the evaluation of a polynomial in a given interval
inline
rs_sign RS_polynomial_1::sign_mpfi(mpfi_srcptr x)const{
        mpfi_t y;
        int l,r,d;
        if(!(d=get_degree())){
                l=mpz_sgn(coef(0));
                return(l?(l>0?RS_POSITIVE:RS_NEGATIVE):RS_ZERO);
        }
        // TODO: fijarse si est� bien la precisi�n (Fabrice dijo que perdemos
        // un bit por operaci�n, hay 2*d operaciones y con tres estar�amos
        // seguros pero dos anda mejor)
        mpfi_init2(y,mpfi_get_prec(x)+2*d);
        mpfi_set_z(y,leading_coefficient());
        for(int i=d-1;i>=0;--i){
                mpfi_mul(y,y,x);
                mpfi_add_z(y,y,coef(i));
        }
        l=mpfr_sgn(&y->left);
        if(l>0){
                mpfi_clear(y);
                return RS_POSITIVE;
        }
        r=mpfr_sgn(&y->right);
        mpfi_clear(y);
        if(r<0)
                return RS_NEGATIVE;
        if(!l&&!r)
                return RS_ZERO;
        return RS_UNKNOWN;
}

} // namespace CGAL

#endif  // CGAL_RS_POLYNOMIAL_1_EVAL_H

// vim: tabstop=8: softtabstop=8: smarttab: shiftwidth=8: expandtab
