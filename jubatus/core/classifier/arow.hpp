// Jubatus: Online machine learning framework for distributed environment
// Copyright (C) 2011 Preferred Networks and Nippon Telegraph and Telephone Corporation.
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License version 2.1 as published by the Free Software Foundation.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

#ifndef JUBATUS_CORE_CLASSIFIER_AROW_HPP_
#define JUBATUS_CORE_CLASSIFIER_AROW_HPP_

#include <string>

#include "linear_classifier.hpp"

namespace jubatus {
namespace core {
namespace classifier {

class arow : public linear_classifier {
 public:
  explicit arow(storage_ptr storage);
  arow(const classifier_config& config, storage_ptr storage);
  void train(const common::sfv_t& fv, const std::string& label);
  std::string name() const;
 private:
  void update(
      const common::sfv_t& fv,
      float alpha,
      float beta,
      const std::string& pos_label,
      const std::string& neg_label);
  classifier_config config_;
};

}  // namespace classifier
}  // namespace core
}  // namespace jubatus

#endif  // JUBATUS_CORE_CLASSIFIER_AROW_HPP_
