/*
 *    This file is part of CasADi.
 *
 *    CasADi -- A symbolic framework for dynamic optimization.
 *    Copyright (C) 2010 by Joel Andersson, Moritz Diehl, K.U.Leuven. All rights reserved.
 *
 *    CasADi is free software; you can redistribute it and/or
 *    modify it under the terms of the GNU Lesser General Public
 *    License as published by the Free Software Foundation; either
 *    version 3 of the License, or (at your option) any later version.
 *
 *    CasADi is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *    Lesser General Public License for more details.
 *
 *    You should have received a copy of the GNU Lesser General Public
 *    License along with CasADi; if not, write to the Free Software
 *    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#ifndef IF_ELSE_NODE_HPP
#define IF_ELSE_NODE_HPP

#include "mx_node.hpp"

namespace CasADi{

/** \brief Represents a branch in an MX tree
  // TODO: Change name of file

  \author Joel Andersson 
  \date 2010
*/
class IfNode : public MXNode{
  public:
    
    /** \brief  Constructors */
    IfNode(const MX& cond, const MX& if_true);

    /// Destructor
    virtual ~IfNode(){}

    /** \brief  Clone function */
    virtual IfNode* clone() const;

    /** \brief  Print */
    virtual void print(std::ostream &stream, const std::vector<std::string>& args) const;

    /** \brief  Evaluate the function and store the result in the node */
    virtual void evaluate(const DMatrixPtrV& input, DMatrixPtrV& output, const DMatrixPtrVV& fwdSeed, DMatrixPtrVV& fwdSens, const DMatrixPtrVV& adjSeed, DMatrixPtrVV& adjSens, int nfwd);
  
  protected:
    
    //! \brief tolerance
    static double tol;
};

} // namespace CasADi


#endif // IF_ELSE_NODE_HPP
