#ifdef __cplusplus
extern "C" {
#endif
#include "lmp_f2c.h"
int ztrsv_(char *uplo, char *trans, char *diag, integer *n, doublecomplex *a, integer *lda,
           doublecomplex *x, integer *incx, ftnlen uplo_len, ftnlen trans_len, ftnlen diag_len)
{
    integer a_dim1, a_offset, i__1, i__2, i__3, i__4, i__5;
    doublecomplex z__1, z__2, z__3;
    void z_lmp_div(doublecomplex *, doublecomplex *, doublecomplex *),
        d_lmp_cnjg(doublecomplex *, doublecomplex *);
    integer i__, j, ix, jx, kx, info;
    doublecomplex temp;
    extern logical lsame_(char *, char *, ftnlen, ftnlen);
    extern int xerbla_(char *, integer *, ftnlen);
    logical noconj, nounit;
    a_dim1 = *lda;
    a_offset = 1 + a_dim1;
    a -= a_offset;
    --x;
    info = 0;
    if (!lsame_(uplo, (char *)"U", (ftnlen)1, (ftnlen)1) && !lsame_(uplo, (char *)"L", (ftnlen)1, (ftnlen)1)) {
        info = 1;
    } else if (!lsame_(trans, (char *)"N", (ftnlen)1, (ftnlen)1) &&
               !lsame_(trans, (char *)"T", (ftnlen)1, (ftnlen)1) &&
               !lsame_(trans, (char *)"C", (ftnlen)1, (ftnlen)1)) {
        info = 2;
    } else if (!lsame_(diag, (char *)"U", (ftnlen)1, (ftnlen)1) &&
               !lsame_(diag, (char *)"N", (ftnlen)1, (ftnlen)1)) {
        info = 3;
    } else if (*n < 0) {
        info = 4;
    } else if (*lda < max(1, *n)) {
        info = 6;
    } else if (*incx == 0) {
        info = 8;
    }
    if (info != 0) {
        xerbla_((char *)"ZTRSV ", &info, (ftnlen)6);
        return 0;
    }
    if (*n == 0) {
        return 0;
    }
    noconj = lsame_(trans, (char *)"T", (ftnlen)1, (ftnlen)1);
    nounit = lsame_(diag, (char *)"N", (ftnlen)1, (ftnlen)1);
    if (*incx <= 0) {
        kx = 1 - (*n - 1) * *incx;
    } else if (*incx != 1) {
        kx = 1;
    }
    if (lsame_(trans, (char *)"N", (ftnlen)1, (ftnlen)1)) {
        if (lsame_(uplo, (char *)"U", (ftnlen)1, (ftnlen)1)) {
            if (*incx == 1) {
                for (j = *n; j >= 1; --j) {
                    i__1 = j;
                    if (x[i__1].r != 0. || x[i__1].i != 0.) {
                        if (nounit) {
                            i__1 = j;
                            z_lmp_div(&z__1, &x[j], &a[j + j * a_dim1]);
                            x[i__1].r = z__1.r, x[i__1].i = z__1.i;
                        }
                        i__1 = j;
                        temp.r = x[i__1].r, temp.i = x[i__1].i;
                        for (i__ = j - 1; i__ >= 1; --i__) {
                            i__1 = i__;
                            i__2 = i__;
                            i__3 = i__ + j * a_dim1;
                            z__2.r = temp.r * a[i__3].r - temp.i * a[i__3].i,
                            z__2.i = temp.r * a[i__3].i + temp.i * a[i__3].r;
                            z__1.r = x[i__2].r - z__2.r, z__1.i = x[i__2].i - z__2.i;
                            x[i__1].r = z__1.r, x[i__1].i = z__1.i;
                        }
                    }
                }
            } else {
                jx = kx + (*n - 1) * *incx;
                for (j = *n; j >= 1; --j) {
                    i__1 = jx;
                    if (x[i__1].r != 0. || x[i__1].i != 0.) {
                        if (nounit) {
                            i__1 = jx;
                            z_lmp_div(&z__1, &x[jx], &a[j + j * a_dim1]);
                            x[i__1].r = z__1.r, x[i__1].i = z__1.i;
                        }
                        i__1 = jx;
                        temp.r = x[i__1].r, temp.i = x[i__1].i;
                        ix = jx;
                        for (i__ = j - 1; i__ >= 1; --i__) {
                            ix -= *incx;
                            i__1 = ix;
                            i__2 = ix;
                            i__3 = i__ + j * a_dim1;
                            z__2.r = temp.r * a[i__3].r - temp.i * a[i__3].i,
                            z__2.i = temp.r * a[i__3].i + temp.i * a[i__3].r;
                            z__1.r = x[i__2].r - z__2.r, z__1.i = x[i__2].i - z__2.i;
                            x[i__1].r = z__1.r, x[i__1].i = z__1.i;
                        }
                    }
                    jx -= *incx;
                }
            }
        } else {
            if (*incx == 1) {
                i__1 = *n;
                for (j = 1; j <= i__1; ++j) {
                    i__2 = j;
                    if (x[i__2].r != 0. || x[i__2].i != 0.) {
                        if (nounit) {
                            i__2 = j;
                            z_lmp_div(&z__1, &x[j], &a[j + j * a_dim1]);
                            x[i__2].r = z__1.r, x[i__2].i = z__1.i;
                        }
                        i__2 = j;
                        temp.r = x[i__2].r, temp.i = x[i__2].i;
                        i__2 = *n;
                        for (i__ = j + 1; i__ <= i__2; ++i__) {
                            i__3 = i__;
                            i__4 = i__;
                            i__5 = i__ + j * a_dim1;
                            z__2.r = temp.r * a[i__5].r - temp.i * a[i__5].i,
                            z__2.i = temp.r * a[i__5].i + temp.i * a[i__5].r;
                            z__1.r = x[i__4].r - z__2.r, z__1.i = x[i__4].i - z__2.i;
                            x[i__3].r = z__1.r, x[i__3].i = z__1.i;
                        }
                    }
                }
            } else {
                jx = kx;
                i__1 = *n;
                for (j = 1; j <= i__1; ++j) {
                    i__2 = jx;
                    if (x[i__2].r != 0. || x[i__2].i != 0.) {
                        if (nounit) {
                            i__2 = jx;
                            z_lmp_div(&z__1, &x[jx], &a[j + j * a_dim1]);
                            x[i__2].r = z__1.r, x[i__2].i = z__1.i;
                        }
                        i__2 = jx;
                        temp.r = x[i__2].r, temp.i = x[i__2].i;
                        ix = jx;
                        i__2 = *n;
                        for (i__ = j + 1; i__ <= i__2; ++i__) {
                            ix += *incx;
                            i__3 = ix;
                            i__4 = ix;
                            i__5 = i__ + j * a_dim1;
                            z__2.r = temp.r * a[i__5].r - temp.i * a[i__5].i,
                            z__2.i = temp.r * a[i__5].i + temp.i * a[i__5].r;
                            z__1.r = x[i__4].r - z__2.r, z__1.i = x[i__4].i - z__2.i;
                            x[i__3].r = z__1.r, x[i__3].i = z__1.i;
                        }
                    }
                    jx += *incx;
                }
            }
        }
    } else {
        if (lsame_(uplo, (char *)"U", (ftnlen)1, (ftnlen)1)) {
            if (*incx == 1) {
                i__1 = *n;
                for (j = 1; j <= i__1; ++j) {
                    i__2 = j;
                    temp.r = x[i__2].r, temp.i = x[i__2].i;
                    if (noconj) {
                        i__2 = j - 1;
                        for (i__ = 1; i__ <= i__2; ++i__) {
                            i__3 = i__ + j * a_dim1;
                            i__4 = i__;
                            z__2.r = a[i__3].r * x[i__4].r - a[i__3].i * x[i__4].i,
                            z__2.i = a[i__3].r * x[i__4].i + a[i__3].i * x[i__4].r;
                            z__1.r = temp.r - z__2.r, z__1.i = temp.i - z__2.i;
                            temp.r = z__1.r, temp.i = z__1.i;
                        }
                        if (nounit) {
                            z_lmp_div(&z__1, &temp, &a[j + j * a_dim1]);
                            temp.r = z__1.r, temp.i = z__1.i;
                        }
                    } else {
                        i__2 = j - 1;
                        for (i__ = 1; i__ <= i__2; ++i__) {
                            d_lmp_cnjg(&z__3, &a[i__ + j * a_dim1]);
                            i__3 = i__;
                            z__2.r = z__3.r * x[i__3].r - z__3.i * x[i__3].i,
                            z__2.i = z__3.r * x[i__3].i + z__3.i * x[i__3].r;
                            z__1.r = temp.r - z__2.r, z__1.i = temp.i - z__2.i;
                            temp.r = z__1.r, temp.i = z__1.i;
                        }
                        if (nounit) {
                            d_lmp_cnjg(&z__2, &a[j + j * a_dim1]);
                            z_lmp_div(&z__1, &temp, &z__2);
                            temp.r = z__1.r, temp.i = z__1.i;
                        }
                    }
                    i__2 = j;
                    x[i__2].r = temp.r, x[i__2].i = temp.i;
                }
            } else {
                jx = kx;
                i__1 = *n;
                for (j = 1; j <= i__1; ++j) {
                    ix = kx;
                    i__2 = jx;
                    temp.r = x[i__2].r, temp.i = x[i__2].i;
                    if (noconj) {
                        i__2 = j - 1;
                        for (i__ = 1; i__ <= i__2; ++i__) {
                            i__3 = i__ + j * a_dim1;
                            i__4 = ix;
                            z__2.r = a[i__3].r * x[i__4].r - a[i__3].i * x[i__4].i,
                            z__2.i = a[i__3].r * x[i__4].i + a[i__3].i * x[i__4].r;
                            z__1.r = temp.r - z__2.r, z__1.i = temp.i - z__2.i;
                            temp.r = z__1.r, temp.i = z__1.i;
                            ix += *incx;
                        }
                        if (nounit) {
                            z_lmp_div(&z__1, &temp, &a[j + j * a_dim1]);
                            temp.r = z__1.r, temp.i = z__1.i;
                        }
                    } else {
                        i__2 = j - 1;
                        for (i__ = 1; i__ <= i__2; ++i__) {
                            d_lmp_cnjg(&z__3, &a[i__ + j * a_dim1]);
                            i__3 = ix;
                            z__2.r = z__3.r * x[i__3].r - z__3.i * x[i__3].i,
                            z__2.i = z__3.r * x[i__3].i + z__3.i * x[i__3].r;
                            z__1.r = temp.r - z__2.r, z__1.i = temp.i - z__2.i;
                            temp.r = z__1.r, temp.i = z__1.i;
                            ix += *incx;
                        }
                        if (nounit) {
                            d_lmp_cnjg(&z__2, &a[j + j * a_dim1]);
                            z_lmp_div(&z__1, &temp, &z__2);
                            temp.r = z__1.r, temp.i = z__1.i;
                        }
                    }
                    i__2 = jx;
                    x[i__2].r = temp.r, x[i__2].i = temp.i;
                    jx += *incx;
                }
            }
        } else {
            if (*incx == 1) {
                for (j = *n; j >= 1; --j) {
                    i__1 = j;
                    temp.r = x[i__1].r, temp.i = x[i__1].i;
                    if (noconj) {
                        i__1 = j + 1;
                        for (i__ = *n; i__ >= i__1; --i__) {
                            i__2 = i__ + j * a_dim1;
                            i__3 = i__;
                            z__2.r = a[i__2].r * x[i__3].r - a[i__2].i * x[i__3].i,
                            z__2.i = a[i__2].r * x[i__3].i + a[i__2].i * x[i__3].r;
                            z__1.r = temp.r - z__2.r, z__1.i = temp.i - z__2.i;
                            temp.r = z__1.r, temp.i = z__1.i;
                        }
                        if (nounit) {
                            z_lmp_div(&z__1, &temp, &a[j + j * a_dim1]);
                            temp.r = z__1.r, temp.i = z__1.i;
                        }
                    } else {
                        i__1 = j + 1;
                        for (i__ = *n; i__ >= i__1; --i__) {
                            d_lmp_cnjg(&z__3, &a[i__ + j * a_dim1]);
                            i__2 = i__;
                            z__2.r = z__3.r * x[i__2].r - z__3.i * x[i__2].i,
                            z__2.i = z__3.r * x[i__2].i + z__3.i * x[i__2].r;
                            z__1.r = temp.r - z__2.r, z__1.i = temp.i - z__2.i;
                            temp.r = z__1.r, temp.i = z__1.i;
                        }
                        if (nounit) {
                            d_lmp_cnjg(&z__2, &a[j + j * a_dim1]);
                            z_lmp_div(&z__1, &temp, &z__2);
                            temp.r = z__1.r, temp.i = z__1.i;
                        }
                    }
                    i__1 = j;
                    x[i__1].r = temp.r, x[i__1].i = temp.i;
                }
            } else {
                kx += (*n - 1) * *incx;
                jx = kx;
                for (j = *n; j >= 1; --j) {
                    ix = kx;
                    i__1 = jx;
                    temp.r = x[i__1].r, temp.i = x[i__1].i;
                    if (noconj) {
                        i__1 = j + 1;
                        for (i__ = *n; i__ >= i__1; --i__) {
                            i__2 = i__ + j * a_dim1;
                            i__3 = ix;
                            z__2.r = a[i__2].r * x[i__3].r - a[i__2].i * x[i__3].i,
                            z__2.i = a[i__2].r * x[i__3].i + a[i__2].i * x[i__3].r;
                            z__1.r = temp.r - z__2.r, z__1.i = temp.i - z__2.i;
                            temp.r = z__1.r, temp.i = z__1.i;
                            ix -= *incx;
                        }
                        if (nounit) {
                            z_lmp_div(&z__1, &temp, &a[j + j * a_dim1]);
                            temp.r = z__1.r, temp.i = z__1.i;
                        }
                    } else {
                        i__1 = j + 1;
                        for (i__ = *n; i__ >= i__1; --i__) {
                            d_lmp_cnjg(&z__3, &a[i__ + j * a_dim1]);
                            i__2 = ix;
                            z__2.r = z__3.r * x[i__2].r - z__3.i * x[i__2].i,
                            z__2.i = z__3.r * x[i__2].i + z__3.i * x[i__2].r;
                            z__1.r = temp.r - z__2.r, z__1.i = temp.i - z__2.i;
                            temp.r = z__1.r, temp.i = z__1.i;
                            ix -= *incx;
                        }
                        if (nounit) {
                            d_lmp_cnjg(&z__2, &a[j + j * a_dim1]);
                            z_lmp_div(&z__1, &temp, &z__2);
                            temp.r = z__1.r, temp.i = z__1.i;
                        }
                    }
                    i__1 = jx;
                    x[i__1].r = temp.r, x[i__1].i = temp.i;
                    jx -= *incx;
                }
            }
        }
    }
    return 0;
}
#ifdef __cplusplus
}
#endif
