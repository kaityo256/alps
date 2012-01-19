#include <alps/parapack/parapack.h>
#include <alps/parapack/exchange.h>
#include <stdlib.h>
//----------------------------------------------------------------------
double
myrand(void){
  return (double)rand()/(double)RAND_MAX;
}
//----------------------------------------------------------------------
class test_worker : public alps::parapack::mc_worker { 
private:
  typedef alps::parapack::mc_worker super_type;
  double value;
  double T;
  const int total_steps;
public:
  test_worker(alps::Parameters const& params) : super_type(params), 
     total_steps(static_cast<double>(evaluate("TOTAL_STEPS",params)))
     {
    value = 0.0;
    T = static_cast<double>(evaluate("T",params));
  };

  virtual ~test_worker() {
  };
  void init_observables(alps::Parameters const&, alps::ObservableSet& obs) {
    obs << alps::RealObservable("Value");
  };
  void save(alps::ODump &dp) const {
  };
  void load(alps::IDump &dp) {
  };
  double progress() const {
    return value;
  };
  bool is_thermalized() const {
    return true;
  };
  void run(alps::ObservableSet& obs) {
    value = value + 1.0/static_cast<double>(total_steps);
    obs["Value"] << myrand()*T;
  };
};
//----------------------------------------------------------------------
int
main( int argc, char **argv) {
  return alps::parapack::start(argc, argv);
}
//----------------------------------------------------------------------
PARAPACK_REGISTER_ALGORITHM(test_worker, "test");
//----------------------------------------------------------------------
