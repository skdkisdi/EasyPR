#ifndef EASYPR_CORE_PLATEJUDGE_H_
#define EASYPR_CORE_PLATEJUDGE_H_

#include "easypr/core/plate.hpp"
#include "easypr/core/feature.h"
#include "easypr/core/core_func.h"

namespace easypr {

class PlateJudge {
 public:
  static PlateJudge* instance();

  //! 对多幅车牌进行SVM判断

  void LoadModel(std::string path);

  int plateJudge(const std::vector<CPlate> &, std::vector<CPlate> &);
  int plateJudgeUsingNMS(const std::vector<CPlate> &, std::vector<CPlate> &, int maxPlates = 5);

  //! 车牌判断

  int plateJudge(const std::vector<Mat> &, std::vector<Mat> &);

  //! 车牌判断（一副图像）

  int plateJudge(const Mat &inMat, int &result);
  int plateSetScore(CPlate& plate);

 private:
  PlateJudge();

  static PlateJudge* instance_;

  svmCallback extractFeature;

  cv::Ptr<ml::SVM> svm_;

};
}

#endif  // EASYPR_CORE_PLATEJUDGE_H_