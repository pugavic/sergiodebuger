<?php

function sergiodebuger_get_add_customers(){
    return <<<EOT
    
EOT;
}

function sergiodebuger_add_customers($customers_counts=531) {
 trc();
    $table_name = "straits_csv_journals";
 /*
    // Drupal 7, dynamic query
$id = db_insert($table_name)
  ->fields(array(
    'intvar' => 5,
    'stringvar' => 'hello world',
    'floatvar' => 3.14,
  ))
  ->execute();*/
  shat("Customeri sozdani $customers_counts shtuk");
  return "Customeri sozdani $customers_counts shtuk";
    
}