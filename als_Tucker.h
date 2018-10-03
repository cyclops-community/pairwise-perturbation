#ifndef __ALS_TUCKER_H__
#define __ALS_TUCKER_H__

#include <ctf.hpp>
using namespace CTF;

void get_factor_matrices(Tensor<>& T, 
             Matrix<>* factor_matrices,
             int ranks[], 
             World& dw);

Tensor<> get_core_tensor(Tensor<>& T, 
             Matrix<>* factor_matrices, 
             int ranks[], 
             World& dw);

void hosvd(Tensor<>& T, 
       Tensor<>& core, 
       Matrix<>* factor_matrices, 
       int * ranks, 
       World& dw);

/* Doing Tensor Times Matrix contraction
*  except index i
*  i=-1 : contract all the indices
*/
void TTMc(Tensor<>& Y, 
      Tensor<>& V,
      Matrix<>* W, 
      int i, 
      World & dw);

/**
 * \brief ALS method for Tucker decomposition
 *  W: output matrices
 *  core: output core tensor
 *  V: input tensor
 *  tol: tolerance for a relative stopping condition
 *  timelimit, maxiter: limit of time and iterations
 */
bool alsTucker(Tensor<> & V, 
         Tensor<> & core, 
         Matrix<> * W, 
         double tol, 
         double timelimit, 
         int maxiter, 
         World & dw);

void ttmc_map_DT(map<string,Tensor<>>& ttmc_map, 
         map<string,string>& parent, 
         map<string,string>& sibling, 
         Tensor<>& V, 
         Matrix<> * W, 
         string args,
         World& dw);

/**
 * \brief ALS method for Tucker decomposition with dimension tree
 *  W: output matrices
 *  core: output core tensor
 *  V: input tensor
 *  tol: tolerance for a relative stopping condition
 *  timelimit, maxiter: limit of time and iterations
 */
bool alsTucker_DT(Tensor<> & V, 
          Tensor<> & core, 
          Matrix<> * W, 
          double tol, 
          double timelimit, 
          int maxiter, 
          ofstream & Plot_File,
          World & dw);

void Build_ttmc_map(map<string, Tensor<>> & ttmc_map, 
          Tensor<> & V, 
          Matrix<> * W,
          char* args,
          World & dw);

/**
 * \brief ALS method for Tucker decomposition with dimension tree PP subroutine
 *  W: output matrices
 *  core: output core tensor
 *  V: input tensor
 *  tol: tolerance for a relative stopping condition
 *  timelimit, maxiter: limit of time and iterations
 */
void alsTucker_DT_sub(Tensor<> & V, 
            Tensor<> & core, 
            Matrix<> * W, 
            double tol, 
            double tol_init,
            double timelimit, 
            int maxiter, 
            double & st_time,
            ofstream & Plot_File,
            int & iter,
            World & dw);

/**
 * \brief ALS method for Tucker decomposition
 *  W: output matrices
 *  core: output core tensor
 *  V: input tensor
 *  tol: tolerance for a relative stopping condition
 *  timelimit, maxiter: limit of time and iterations
 */
bool alsTucker_PP(Tensor<> & V, 
          Tensor<> & core, 
          Matrix<> * W, 
          double tol, 
          double tol_init,
          double timelimit, 
          int maxiter, 
          ofstream & Plot_File,
          World & dw) ;




#endif